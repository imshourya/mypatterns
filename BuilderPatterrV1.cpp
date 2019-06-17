#include<iostream> 
using namespace std; 


//Builder design pattern implementation
//Intent :Builder is a creational design pattern that lets you construct complex objects step by step. 
//The pattern allows you to produce different types and representations of an object using the same construction code.
//The Builder pattern suggests that you extract the object construction code out of its own class and move it to separate objects called builders.
//Use the Builder pattern to get rid of a “telescopic constructor”.
//Use the Builder pattern when you want your code to be able to create different representations of some product (for example, stone and wooden houses).
//Abstract Product with needed fuctions

class Button 
{
	public: 
	int Length ;
	int Width ;
	string Theme;
	int Color ;
	int Radius;
	string Style ;
	Button (string btn)
	{
		std::cout << "Creating button for "  << btn << std::endl; 
	}
	void setLength(int pl) { Length = pl;}
	void setWidth(int pw) { Width = pw  ;}
	void setTheme(string pt) { Theme = pt ;}
	void setColor(int pc) { Color = pc ;}
	void setRadius(int pr) { Radius = pr;}
	void setStyle(string ps) { Style= ps ;}
	void paint()
	{
		std::cout << "Length created"  << Length << std::endl;
		std::cout << "Width created"  <<  Width << std::endl;
		std::cout << "Theme created"  << Theme  <<std::endl;
		std::cout << "Color created"  << Color <<std::endl;
		std::cout << "Radius created"  << Radius <<std::endl;
		std::cout << "Style created"  << Style<<std::endl;
	}
};



//Abstract Gui Factory with factory methods which returns Button object
class ButtonBuilder
{
	public :virtual void  getButtonLength()=0;
	public :virtual void  getButtonWidth()=0;
	public :virtual void  getButtonTheme()=0;
	public :virtual void  getButtonColor()=0;
	public :virtual void  getButtonRadius()=0;
	public :virtual void  getButtonStyle()=0;
	protected :Button*mb;
	public : Button* getButton( ){return mb ;}
};

class LinuxButtonBuilder :public ButtonBuilder
{
	public :
			LinuxButtonBuilder(){ mb = new Button("Linux");}
			void  getButtonLength() { mb->setLength (10);}
			void  getButtonWidth() { mb->setWidth (10);}
			void  getButtonTheme() { mb->setTheme ("LinuxTheme");}
			void  getButtonColor() { mb->setColor (10);}
			void  getButtonRadius() { mb->setRadius (10);}
			void  getButtonStyle() { mb->setStyle ("LinuxStyle");}
};

class WindowsButtonBuilder :public ButtonBuilder
{
	public :
			WindowsButtonBuilder(){ mb = new Button("Window");}
			void  getButtonLength() { mb->setLength (10);}
			void  getButtonWidth() { mb->setWidth (10);}
			void  getButtonTheme() { mb->setTheme ("Windowheme");}
			void  getButtonColor() { mb->setColor (10);}
			void  getButtonRadius() { mb->setRadius (10);}
			void  getButtonStyle() { mb->setStyle ("WindowStyle");}
};


class ButtonDirector 
{
	ButtonBuilder *btnbldr;
	public: 
			void createButton() 
			{
				btnbldr->getButtonLength();
				btnbldr->getButtonWidth();
				btnbldr->getButtonTheme();
				btnbldr->getButtonColor();
				btnbldr->getButtonRadius();
				btnbldr->getButtonStyle();
			}
			void setBuilder(ButtonBuilder* pbtnbldr){btnbldr = pbtnbldr;}
};

int main() 
{ 
	
	LinuxButtonBuilder lbtn;
	//WindowsButtonBuilder wbtn;
	ButtonDirector bd;
	bd.setBuilder(&lbtn);
	bd.createButton();
	lbtn.getButton()->paint();
	
	WindowsButtonBuilder wbtn;
	bd.setBuilder(&wbtn);
	bd.createButton();
	wbtn.getButton()->paint();
	return 0; 
} 
