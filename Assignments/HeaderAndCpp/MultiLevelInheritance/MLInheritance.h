class BaseClass {
	public:
		BaseClass();
		void BaseFunc();
		~BaseClass();
};

class ChildClass: public BaseClass {
	public:
		ChildClass();
		void ChildFunc();
		~ChildClass();
};

class GrandChild: public ChildClass {
	public:
		GrandChild();
		void GrandChildFunc();
		~GrandChild();
};

