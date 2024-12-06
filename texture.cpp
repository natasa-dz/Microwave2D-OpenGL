#include <freetype/ftimage.h>

#include"texture.h"
#include "../libraries/include/stb/stb_image.h"

Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType)
{
	type = texType;

	int widthImg, heightImg, numColCh;

	stbi_set_flip_vertically_on_load(true);

	unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

	if (!bytes)
	{
		std::cerr << "Failed to load texture: " << image << std::endl;
		return;
	}


	std::cout << "Loaded texture: " << image
		<< " (" << widthImg << "x" << heightImg << ", "
		<< numColCh << " channels)" << std::endl;

	// Determine the appropriate format if not specified
	GLenum internalFormat = (numColCh == 4) ? GL_RGBA : GL_RGB;


	glGenTextures(1, &ID);

	glActiveTexture(slot);
	glBindTexture(texType, ID);


	//glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	//glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//simplified for debugging:
	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);



	glTexImage2D(texType, 0, internalFormat, widthImg, heightImg, 0, format, pixelType, bytes);

	glGenerateMipmap(texType);


	stbi_image_free(bytes);


	glBindTexture(texType, 0);
}


//Texture::Texture(FT_Bitmap& bitmap, GLenum texType, GLenum slot)
//{
//	type = texType;
//
//	glGenTextures(1, &ID);
//
//	glActiveTexture(slot);
//	glBindTexture(texType, ID);
//
//	glTexImage2D(
//		texType,
//		0,
//		GL_RED,
//		bitmap.width,
//		bitmap.rows,
//		0,
//		GL_RED,
//		GL_UNSIGNED_BYTE,
//		bitmap.buffer
//	);
//
//	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	glBindTexture(texType, 0);
//}


void Texture::assignUnit(Shader& shader, const char* uniform, GLuint unit)
{
	GLuint texUnit = glGetUniformLocation(shader.ID, uniform);

	shader.Activate();
	glUniform1i(texUnit, unit); // Assign texture unit to sampler
}

void Texture::Bind()
{
	glBindTexture(type, ID);
}

void Texture::Unbind()
{
	glBindTexture(type, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}