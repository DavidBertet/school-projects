#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "textures.hh"

static void	load_loop_for(GLuint		imageSize,
			      GLuint		bytesPerPixel,
			      s_texture_image*  texture)
{
  GLuint        i = 0;
  GLuint        temp;

  for (; i < imageSize; i += bytesPerPixel)
    {
      temp = texture->imageData[i];
      texture->imageData[i] = texture->imageData[i + 2];
      texture->imageData[i + 2] = temp;
    }
  return;
}

static void	load_bind_glTex(s_texture_image* texture)
{
  GLuint        type = GL_RGBA;
  GLuint	arg1 = GL_TEXTURE_2D;
  GLuint	arg2 = GL_UNSIGNED_BYTE;
  GLuint	w;
  GLuint	h;

  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  if (texture[0].bpp==24)
    type = GL_RGB;
  w = texture[0].width;
  h = texture[0].height;
  glTexImage2D(arg1, 0, type, w, h, 0, type, arg2, texture[0].imageData);
  return;
}

static int	load_tga(s_texture_image*	texture,
			 std::string		filename)
{
  GLubyte	TGAcompare[12];
  GLubyte	header[6];
  GLuint	bytesPerPixel;
  GLuint	imageSize;
  FILE		*file = NULL;

  file = fopen(filename.c_str (), "rb");
  fread(TGAcompare, 1, sizeof (TGAcompare), file);
  fread(header, 1, sizeof (header), file);
  texture->width = header[1] * 256 + header[0];
  texture->height = header[3] * 256 + header[2];
  texture->bpp = header[4];
  bytesPerPixel = texture->bpp / 8;
  imageSize = texture->width * texture->height * bytesPerPixel;
  texture->imageData = (GLubyte*) malloc(imageSize);
  fread(texture->imageData, 1, imageSize, file);
  load_loop_for(imageSize, bytesPerPixel, texture);
  fclose(file);
  glGenTextures(1, &texture[0].texID);
  glBindTexture(GL_TEXTURE_2D, texture[0].texID);
  load_bind_glTex(texture);
  return (0);
}

int	load_textures(std::vector <s_texture_image*>& tab)
{
  tab.push_back (new s_texture_image);
  load_tga(tab[0], "bonus/white_king.tga");

  tab.push_back (new s_texture_image);
  load_tga(tab[1], "bonus/white_queen.tga");

  tab.push_back (new s_texture_image);
  load_tga(tab[2], "bonus/white_rook.tga");

  tab.push_back (new s_texture_image);
  load_tga(tab[3], "bonus/white_bishop.tga");

  tab.push_back (new s_texture_image);
  load_tga(tab[4], "bonus/white_knight.tga");

  tab.push_back (new s_texture_image);
  load_tga(tab[5], "bonus/white_pawn.tga");

  tab.push_back (new s_texture_image);
  load_tga(tab[6], "bonus/black_king.tga");

  tab.push_back (new s_texture_image);
  load_tga(tab[7], "bonus/black_queen.tga");

  tab.push_back (new s_texture_image);
  load_tga(tab[8], "bonus/black_rook.tga");

  tab.push_back (new s_texture_image);
  load_tga(tab[9], "bonus/black_bishop.tga");

  tab.push_back (new s_texture_image);
  load_tga(tab[10], "bonus/black_knight.tga");

  tab.push_back (new s_texture_image);
  load_tga(tab[11], "bonus/black_pawn.tga");

  return (0);
}
