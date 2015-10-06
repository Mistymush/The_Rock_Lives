namespace df{

	class Singleton {
	private:
		Singleton();
		Singleton(Singleton const &copy);

		//Singleton&(Singleton const &assign);
	public:
		//Singleton access function
		static Singleton &getInstance();
	};



}