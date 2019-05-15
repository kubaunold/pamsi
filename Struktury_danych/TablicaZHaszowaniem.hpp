#ifndef TABLICAZHASZOWANIEM_HPP
#define TABLICAZHASZOWANIEM_HPP

//#include <typeinfo>

#define ARR_SIZE 100



template <typename KeyType, typename ValueType>
class Map // Tablica z haszowaniem
{
private:
	ValueType tab[ARR_SIZE]{0};	//tablica 100 elementow zainicjalizowana zerami
	int HashFun(const KeyType& key);
public:
	void insert(const KeyType & key, const ValueType & value);
	ValueType& operator () (const KeyType& key );
	void remove(const KeyType& key);
	
};

template<typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value)
{
	tab[HashFun(key)] = value;	//dziala bez this!
}

template<typename KeyType, typename ValueType>
ValueType& Map<KeyType, ValueType>::operator() (const KeyType& key)
{
	return tab[HashFun(key)];
}

template<typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::remove(const KeyType& key)
{
	tab[HashFun(key)] = 0;
}

template<typename KeyType, typename ValueType>
int Map<KeyType, ValueType>::HashFun(const KeyType& password)
{
	//std::cout << password[0];
	//std::string imie("Ala");
	//std::cout << imie.size() << "!!!!!!!!!!!!!!!!!!!!!!!";
	if (typeid(KeyType).name() == typeid(std::string).name())	//jesli KeyType to string
	{
		
		std::cout << "klucz to STRING\n";

		int sum(0);	//{te¿ zadziala}
		for (int i(0); password[i] != '\0'; ++i)
		{
			sum += password[i] * (i + 1);
		}
		return sum%ARR_SIZE;
	}
	//PROBLEM: dzielenie dzia³ania funkcji w zaleznosci od typu argumentu...
	//else
	//	if (typeid(KeyType).name() == typeid(int).name())
	//{
	//	std::cout << "klucz to INT";
	//	return password % ARR_SIZE;
	//}
	else
	{
		throw "Key type must be INT or STRING";
	}

	return 1;
}

#endif // !TABLICAZHASZOWANIEM_HPP