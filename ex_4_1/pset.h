#ifndef PSET_H_
#define PSET_H_

#include <fstream>
#include <set>
#include "persistence_traits.h"

template<typename T, typename P=persistence_traits<T>>
class pset : public std::set<T>
{

	const std::string file;

	void load()
	{
		std::ifstream ifs(file);

		for (;;) {
			T t;
			P::read(ifs, t);
			if (!ifs.good())
				break;
			std::set<T>::insert(t);
		}
	}

	void save()
	{
		std::ofstream ofs(file);

		for (const T& t : *this) {
			P::write(ofs, t);
		}
	}

public:

	pset(const std::string& file) : file(file)
	{
		load();
	}

	~pset()
	{
		save();
	}

};

#endif  // PSET_H_
