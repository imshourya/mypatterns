#include<iostream> 
using namespace std; 


//Leagy payment methods
class Payment
{
	public:virtual void  DoPayment()=0;

};

class CardPayment : public Payment
{
	public : void  DoPayment(){ std::cout << "Card Payment done "  << std::endl;}

};

class NetBankingPayment : public Payment
{
	public : void  DoPayment(){ std::cout << "NetBankingPayment  done "  << std::endl;}

};

//new payment interface 
class UPIpayment
{
	public : virtual   string makepayment()=0;

};

class Paytm : public UPIpayment
{
	public : virtual   string makepayment()
	{
		std::cout << "Paytm Payment done "  << std::endl;
		return "Paytm karo";
	}
};


class PhonePe : public UPIpayment
{
	public : virtual   string makepayment()
	{
		std::cout << "PhonePe Payment done "  << std::endl;
		return "PhonePe karo";
	}
};

class PaymentAdapter : public Payment
{
	UPIpayment *m_upi;
	public: PaymentAdapter(UPIpayment *upi){ m_upi=upi;}
	public: void DoPayment() { m_upi->makepayment();}

};

class PaymentClient 
{
	Payment *oldPaymentMethod;
	public :
		void selectPayment(Payment *payment) { oldPaymentMethod = payment;};
		void pay ( ){ oldPaymentMethod-> DoPayment();}
};


int main ()
{
	//Payment *pay = new CardPayment;
	//pay->DoPayment();
	//pay = new NetBankingPayment;
	//pay->DoPayment();
	//Paytm *ptm = new Paytm;
	//PaymentAdapter *pa = new PaymentAdapter(ptm);
	//pa->DoPayment();
	//PhonePe *Ppe = new PhonePe;
	//PaymentAdapter *paa = new PaymentAdapter(Ppe);
	//paa->DoPayment();
	PaymentClient *pc = new PaymentClient;
	pc->selectPayment(new CardPayment);
	pc->pay();
	pc->selectPayment(new NetBankingPayment);
	pc->pay();
	
	PaymentAdapter *pa = new PaymentAdapter(new Paytm);
	pc->selectPayment(pa);
	pc->pay();
    pa = new PaymentAdapter(new PhonePe);
	pc->selectPayment(pa);
	pc->pay();
	

	return 0;
}