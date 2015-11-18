#include <iostream>
#include <typeinfo>

using namespace std;

//Runtime polymorphism using virtual function

class BridgeIf {
	public:
		virtual void operationA(void)=0;
		virtual void operationB(void)=0;
};
template <typename T>
class BridgeImpl : public BridgeIf {
	private:
		void show_type() { cout << "++++++" << typeid(T).name() << "++++++++";};
	public:
	virtual void operationA(void) { cout << endl << "Operation A for type "; show_type();};
	virtual void operationB(void) { cout << endl << "Operation B for type ";show_type();};
};

class Bridge {
	private:
		BridgeIf * pImpl;
	public:
		Bridge(BridgeIf &bImpl):pImpl(&bImpl){};
		void operationA(void) { pImpl->operationA();};
		void operationB(void) { pImpl->operationB();};
};

//Compile time polymorphism

template <typename T>
class TemplBridge {
	public:
	void operationA(void) { (static_cast<T *>(this))->operationA();};
	void operationB(void) { (static_cast<T *>(this))->operationB();};
};

class BridgeImpl1 : public TemplBridge<BridgeImpl1>
{
	private:
	void show_type() { cout << "-----" << typeid(this).name() << "---------";};
	public:
	void operationA(void) { cout << endl << "Operation A for type "; show_type();};
	void operationB(void) { cout << endl << "Operation B for type ";show_type();};
};

int
main(int argc, char **argv)
{
	BridgeImpl<int> bImpl;
	BridgeImpl<char> bImpl1;
	Bridge bridge(bImpl);
	Bridge bridge1(bImpl1);
	bridge.operationA();
	bridge.operationB();
	bridge1.operationA();
	bridge1.operationB();
	TemplBridge<BridgeImpl1> tbc;
	tbc.operationA();
	tbc.operationB();
}
