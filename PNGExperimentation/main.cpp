#include <iostream>
#include <fstream>

int main()
{
	FILE* output_file = fopen("output.png", "wb");
	if(!output_file)
	{
		std::cerr << "Unable to open output file" << std::endl;
		return 1;
	}

	png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, (png_voidp)user_error_ptr, user_error_fn, user_warning_fn);

	return 0;
}
