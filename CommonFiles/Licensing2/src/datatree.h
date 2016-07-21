/* Generated by Together */

#ifndef DATATREE_H
#define DATATREE_H

namespace KasperskyLicensing{
namespace Implementation{

//-----------------------------------------------------------------------------

class bad_data_format : public std::runtime_error
{
public:
	bad_data_format() 
		: std::runtime_error("bad data format") {}
};

class node_not_found : public std::runtime_error
{
public:
	node_not_found() 
		: std::runtime_error("node not found") {}
};

class bad_value_cast : public std::runtime_error
{
public:
	bad_value_cast() 
		: std::runtime_error("bad value cast") {}
};

class bad_data_size : public std::runtime_error
{
public:
	bad_data_size() 
		: std::runtime_error("bad data size") {}
};


//-----------------------------------------------------------------------------

/**
 * Data tree abstraction.
 */
class data_tree
{
public:
	class node;
	class value;

	/**
	 * Constructs data tree by given binary data.
	 */
	data_tree(const void* data, size_t size);

	/**
	 * Destroys data tree.
	 */
	~data_tree();

	/**
	 * Returns root node of data tree.
	 */
	node get_root();

private:
	class kldt_library;

	// root handle
	HDATA root;

	// data tree library initializer
	static kldt_library libkldt;
};

//-----------------------------------------------------------------------------

/**
 * Extracts value stored in the data tree node.
 */
class data_tree::value
{
public:
	/**
	 * Constructs object and binds it to given node.
	 */
	explicit value(HDATA handle);

	/**
	 * Returns type of stored value.
	 */
	AVP_TYPE type() const;

	/**
	 * Casts value to unsigned int.
	 */
	unsigned as_uint() const;

	/**
	 * Casts value to date.
	 */
	time_t as_date() const;

	/**
	 * Casts value to string.
	 */
	void as_string(std::basic_string<char_t>& str) const;

	/**
	 * Casts value to binary.
	 */
	size_t as_binary(void* data, size_t size) const;

private:

	// handle of node
	HDATA hdata;
};

//-----------------------------------------------------------------------------

/**
 * Node of data tree.
 */
class data_tree::node
{
public:

	/**
	 * Node of data tree.
	 */
	typedef Enumerator<node> child_enumerator;

	/**
	 * Constructs data tree node.
	 */
	explicit node(HDATA handle);

	/**
	 * Returns node identifier.
	 */
	unsigned id() const;

	/**
	 * Returns child by given id.
	 */
	node get_child(unsigned id) const;

	/**
	 * Returns children enumerator.
	 */
	child_enumerator get_children() const;

	/**
	 * Returns value of data tree node.
	 */
	value get_value() const;
	
private:
	
	// node handle
	HDATA hdata;

};

//-----------------------------------------------------------------------------

/**
 * Data tree library initializer.
 */
class data_tree::kldt_library
{
public:

	/**
	 * Performs library initialization.
	 */
	kldt_library();

	/**
	 * Performs library deinitialization.
	 */
	~kldt_library();
};

//-----------------------------------------------------------------------------

} // namespace Implementation
} // namespace KasperskyLicensing

#endif //DATATREE_H