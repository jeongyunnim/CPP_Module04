# CPP_Module04
Subtype polymorphism, abstract classes, interfaces

## Exercise00: 다형성

모든 예제에서 가능한 한 완벽한 테스트를 제공해야 한다.
각 클래스의 생성자와 소멸자는 특정한 메세지를 표출해야 한다. 모든 클래스의 출력을 다르게 설정하라.

Animal 클래스를 만드는 것으로 시작해보자. 
protected 변수 type을 가지고 있다.
protected:
	std::string type;

Animal을 상속받는 Dog을 구현하라.
Animal을 상속받는 Cat을 구현하라.

두 파생 클래스의 type은 각각 다르게 설정되어야 한다. Dog 클래스는 "Dog"으로, Cat 클래스는 "Cat"으로 설정하라.
Animal 클래스의 type은 비워두거나, 임의의 값으로 설정해도 된다.

모든 animal 클래스는 makeSound() 메서드를 사용할 수 있어야 한다.
이 메서드는 적절한 소리를 출력한다. (고양이는 짖을 수 없다)

아래의 함수를 실행시켜라.
Animal이 아닌 Dog와 Cat 클래스의 특정한 소리를 출력해야 한다.
```
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	...

	return 0;
}
```
어떻게 작동하는지 확실히 하기 위해서, WrongCat클래스를 구현하라. 이는 WrongAnimal 클래스를 상속 받는다. Animal과 Cat을 대체하여 실행시켜 보아라. WrongCat은 WrongAnimal의 소리를 출력해야 한다.

위에서 제시된 테스트보다 더 많은 테스트를 구현하라.

## Exercise 01: I don't want to set the world on fire

각 클래스의 생성자와 소멸자는 특정 메세지를 표출해야 한다.

`std::string ideas[100]` 변수를 가지는 Brain 클래스를 구현하라.

Dog와 Cat은 `Brain *` 특성을 private 변수로 가진다.
Dog와 Cat의 생성자는 `new Brain()`을 통해 Brain을 생성한다.
소멸자는 delete를 통해 Brain을 소멸시킨다.

main() 에서는 Animal의 오브젝트 배열을 생성하고 채워야 한다. 절반은 Dog의 오브젝트로 채우고 나머지 절반은 Cat의 오브젝트로 채워라. 프로그램이 종료될 때 해당 배열을 순회하여 모든 Animal을 delete 해야한다. dog 와 cat은 Animal로서 delete 해야 한다. 적절한 소멸자의 메세지가 적절한 순서에 따라 표출되어야 한다.

메모리 누수가 일어나서는 안 된다.

Dog와 Cat은 얕은 복사가 일어나서는 안 된다. 깊은 복사를 했는지 테스트 해야 한다.

```
int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;//should not create a leak
	delete i;
	...
	
	return 0;
}
```
위의 테스트를 더욱 보완하여 테스트하라.

## Exercise 02: Abstract class

Animal 오브젝트를 만드는 것은 말이 되지 않는다. 사실 동물 자체는 소리를 내지 않는다!

실수를 방지하기 위해 Animal 클래스는 인스턴스화 할 수 없어야 한다. Animal 클래스를 인스턴스화 할 수 없도록 고쳐라. 모든 것이 이전과 같이 작동해야 한다.

원하는 경우 Animal에 접두사 A를 붙여 클래스 이름을 업데이트할 수 있다.

## Exercise 03: Interface & recap

Interface는 C++98에서 지원하지 않는다. 하지만 일반적으로 순수 가상 함수는 인터페이스라고 불린다. 그러므로 현재 예제에서 이 모듈을 확실히 이해하기 위해 인터페이스를 구현해보도록 하겠다.

다음 AMateria 클래스를 정의하고 필요한 멤버 함수를 구현하라.
```
class AMateria
{
	protected:
		[...]

	public:
		AMateria(std::string const & type);
		[...]
		
		std::string const & getType() const; //Returns the materia type
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
```

구체 클래스 Ice 와 Cure를 구현하라. "ice", "cure"이 각각의 type으로 지정이 되어야 한다. 물론 멤버 함수 clone()은 같은 타입의 새로운 인스턴스를 반환할 것이다. (즉, 만약 Ice Materia를 clone 한다면 새로운 Ice Materia를 얻게 될 것이다)

- void use(ICharacter& Character);
	: 이 멤버 함수는 아래의 메세지를 표출한다.
	• Ice: "* shoots an ice bolt at <name> *"
	• Cure: "* heals <name>’s wounds *"
	<name>은 파라미터로 전달받은 Character의 변수이다. 꺽쇠를 프린트 하지 마라.

! Materia를 다른 Materia에 할당하는 동안 유형을 복사하는 것은 의미가 없다.

아래의 인터페이스를 구현하는 구체 클래스 Character를 구현하라. 
```
class ICharacter
{
public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};
```

Character는 4슬롯의 인벤토리를 소유하고 있다. 각 슬롯에는 Materia를 저장할 수 있다. 인스턴스 생성시 인벤토리는 비어있으며, Materia는 비어있는 인벤토리의 첫 번째 슬롯부터 착용한다(0번째 슬롯에서 3번째 슬롯 순서). 모든 인벤토리가 차있는 상태에서 Materia를 착용하려는 경우, 혹은 비어있는 상태에서 착용 해제하려는 경우 아무것도 하지 않는다. unequip() 멤버 함수는 Materia를 delete 해서는 안된다!

! 캐릭터가 버린 Materia들은 원하는 대로 처리하라.
unequip() 등을 호출하기 전에 주소를 저장하는 등의 처리를 해야 한다. 
메모리 누수가 일어나면 안 된다.

use(int index, ICharacter& character) 멤버함수는 인벤토리의 index에 있는 Materia를 사용해야 한다. 또한 AMateria::use 함수를 통해 타겟을 파라미터로 넘겨주어야 한다.

! 캐릭터의 인벤토리는 모든 유형의 AMateria를 지원해야 한다.

캐릭텨의 이름을 파라미터로 받는 생성자가 있어야 한다. 복사 생성자 또는 할당 연산자는 반드시 깊은 복사를 해야 한다. 복사하는 동안 캐릭터의 Materia는 새로운 Materia가 인벤토리에 추가되기 전에 삭제되어야 한다. 캐릭터가 삭제될 때도 삭제외어야 한다. 

다음 인터페이스를 구현하는 구체 클래스 MateriaSource를 작성하라.
```
class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};
```

• learnMateria(AMateria*)
	:전달받은 인자의 Materia를 복사하여 클론할 수 있도록 메모리를 저장한다. 캐릭터 처럼 MateriaSource는 4개의 Materia를 저장할 수 있다. 요소가 유일할 필요성은 없다.

• createMateria(std::string const &)
	새로운 Materia를 반환한다. latter는 이전에 MateriaSource가 learnMateria()에 저장된 유형과 동일하다. 유형을 알 수 없으면 0을 반환한다.
	MateriaSource는 필요할 때 생성할 수 있는 Materia의 "템플릿"을 학습할 수 있어야 한다. 유형을 식별하는 문자열만 사용하여 새로운 Materia를 생성할 수 있다. 

```
int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	
	return 0;
}
```
위의 코드를 실행하라

아래의 결과가 나와야 한다.
```
$> clang++ -W -Wall -Werror *.cpp
$> ./a.out | cat -e
* shoots an ice bolt at bob *$
* heals bob's wounds *$
```
추가적인 테스트 코드를 작성하라.