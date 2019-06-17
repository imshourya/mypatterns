#include<iostream> 
using namespace std; 


//Factory method design pattern implementation


//Abstract Product with needed fuctions
class Button 
{
	public:virtual void paint()=0;
};

//concrete classes 
class LinuxButton : public Button 
{
	public : void paint () { std::cout << "Linux Button created"  << std::endl;}
};

class MacButton : public Button 
{
	public : void paint () { std::cout << "MacButton created"  << std::endl;}
};

class WinButton : public Button 
{
	public : void paint () { std::cout << "WinButton created"  << std::endl;}
};
class DefaultButton: public Button 
{
	public : void paint () { std::cout << "DefaultButton created"  << std::endl;}
};


//Abstract Gui Creator Classs with factory method which returns Button object
class GuiFactory
{
	public :virtual Button* createButton(string OStype)
	{
		if (OStype == "")
		{
			std::cout << " GuiFactory DefaultButton created"  << std::endl;
			return  new DefaultButton;
		}
	}
};

//Concrete Button factory class 
class ButtonFactory : public GuiFactory
{
	public : Button* createButton ( string OStype)
	{	
		Button *b = GuiFactory::createButton("");
		if (OStype == "Linux")
			b = new LinuxButton;
		if (OStype == "Mac")
			b = new MacButton;
		if (OStype == "Windows")
			b = new WinButton;
		return b;
	}
};

int main() 
{ 
	//client code knows about only abstract class;
	GuiFactory *gf;
	Button *btn;
	gf = new ButtonFactory();
	btn = gf->createButton("Linux");
	btn->paint();

	btn = gf->createButton("Mac");
	btn->paint();
    
	btn = gf->createButton("Windows");
	btn->paint();
	
	btn = gf->createButton("");
	btn->paint();
	delete gf;
	return 0; 
} 
