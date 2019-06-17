#include<iostream> 
using namespace std; 


//Abstract factory design pattern implementation
//Intent :Provide an interface for creating families of related or dependent objects without specifying their concrete classes.


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


class ScrollBar 
{
	public:virtual void paint()=0;
};

//concrete classes 
class LinuxScrollBar : public ScrollBar 
{
	public : void paint () { std::cout << "Linux ScrollBar created"  << std::endl;}
};

class MacScrollBar : public ScrollBar 
{
	public : void paint () { std::cout << "MacScrollBar created"  << std::endl;}
};

class WinScrollBar : public ScrollBar 
{
	public : void paint () { std::cout << "WinScrollBar created"  << std::endl;}
};
class DefaultScrollBar: public ScrollBar 
{
	public : void paint () { std::cout << "DefaultScrollBar created"  << std::endl;}
};



//Abstract Gui Factory with factory methods which returns Button object
class GuiFactory
{
	public :virtual Button* createButton()=0;
	public :virtual ScrollBar* createScrollBar()=0;
};

//Concrete Mac widget  factory class 
class MacWidgetFactory : public GuiFactory
{
	public : Button* createButton ( ){ return MacButton;}
	public : ScrollBar* createScrollBar ( ){ return MacScrollBar;}
};


class WindowsWidgetFactory : public GuiFactory
{
	public : Button* createButton ( ){ return WinScrollBar;}
	public : ScrollBar* createScrollBar ( ){ return WinScrollBar;}
};

class LinuxWidgetFactory : public GuiFactory
{
	public : Button* createButton ( ){ return LinuxButton;}
	public : ScrollBar* createScrollBar (){ return LinuxScrollBar;}
};



int main() 
{ 
	//client code knows about only abstract class;
	GuiFactory *gf;
	Button *btn;
	ScrollBar *sb;
	gf = new MacWidgetFactory();
	btn = gf->createButton();
	btn->paint();
	sb = gf->createScrollBar();
	sb->paint();

	gf = new WindowsWidgetFactory();
	btn = gf->createButton();
	btn->paint();
	sb = gf->createScrollBar();
	sb->paint();
	
	gf = new LinuxWidgetFactory();
	btn = gf->createButton();
	btn->paint();
	sb = gf->createScrollBar();
	sb->paint();

	delete gf;
	return 0; 
} 
