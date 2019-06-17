//Prototype design pattern 
//Prototype is a creational design pattern that lets you copy existing objects without making your code dependent on their classes.
//You can get rid of repeated initialization code in favor of cloning pre-built prototypes.
//You get an alternative to inheritance when dealing with configuration presets for complex objects.
//Kind of a virtual copy constructor .Lets clint to clone objet of derived class with given pointer to base class.
#include<iostream> 
using namespace std; 

class IBase{
public:
    // Destructor always virtual to avoid memory leak,
    virtual ~IBase() = default; 
    // "virtual copy constructor"
    virtual IBase* clone()  = 0;
    // "virtual default constructor"
    virtual IBase*  create() = 0;  
    virtual string getID()= 0;
    virtual void  setID(std::string id) = 0;
    virtual void  show() = 0;
};

class DerivedA: public IBase{
private: 
	string _id;
public:
	DerivedA(): _id("unnamed-A"){ }
	DerivedA(std::string id): _id{std::move(id)}{  }
	IBase* clone() 
	{
	// Invoke copy constructor 
		return new DerivedA(*this);
	}
	IBase*  create() 
	{
		// Invoke default constructor 
		return new DerivedA();
	}
	string getID()  {return _id;}
	void setID(std::string id){_id = id;}   
	void show() {std::cout << " => Class DerivedA - id = " << _id << "\n";}
};

class DerivedB: public IBase{
private:
		std::string _id;
public:
		DerivedB(): _id("unnamed-B"){ }
		DerivedB(std::string id): _id{std::move(id)}{  }

	IBase* clone() 
	{
		// Invoke copy constructor 
		return new DerivedB(*this);
	}
	IBase*  create() 
	{
		// Invoke default constructor 
		return new DerivedB();
	}
	string getID()  {return _id;}
	void setID(std::string id){_id = id;}   
	void show() {std::cout << " => Class DerivedB - id = " << _id << "\n";}
};


int main ()
{
//	DerivedA da("objectA");
	DerivedB db("objectB");
//	da.show();
//	db.show();
    IBase* ptr = new DerivedA("objectA");
	ptr->getID();
	ptr->show();
	
	IBase * clone = ptr->clone();
	clone->show();
	clone->setID("Clone");
	clone->show();
	
	ptr = &db;
	ptr->show();
	IBase* clone2 = ptr->create();
	clone2->show();
	return 0;
}


