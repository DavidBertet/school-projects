#ifndef TEXTURES_H_
# define TEXTURES_H_

# include <vector>
# include "GL/gl.h"

typedef struct  texture_image
{
  GLubyte       *imageData;
  GLuint        bpp;
  GLuint        width;
  GLuint        height;
  GLuint        texID;
}               s_texture_image;

int	load_textures(std::vector <s_texture_image*>& tab);

#endif /* !TEXTURES_H_ */
