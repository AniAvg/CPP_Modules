#include "Serializer.hpp"
#include "Data.hpp"

int	main()
{
	Data data;
	data.number = 32;
	data.name = "Annie";

	uintptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);

	std::cout << "Original pointer: " << &data << std::endl;
	std::cout << "Deserialized pointer: " << ptr << std::endl;

	if (&data == ptr)
		std::cout << "Success!" << std::endl;
	else
		std::cout << "Failure!" << std::endl;

	return 0;
}
