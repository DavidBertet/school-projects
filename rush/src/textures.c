#include "func.h"

static void	load_loop_for(GLuint		imageSize,
			      GLuint		bytesPerPixel,
			      s_texture_image	*texture)
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

static void	load_bind_glTex(s_texture_image	*texture)
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

static int	load_tga(s_texture_image	*texture,
			 char			*filename)
{
  GLubyte	TGAcompare[12];
  GLubyte	header[6];
  GLuint	bytesPerPixel;
  GLuint	imageSize;
  FILE		*file = NULL;

  file = fopen(filename, "rb");
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

static void	load_part_1(s_game	*game)
{
  load_tga(&(game->txt[TEXT_MAINSHIP1 - 2]), "pic/sprite_ship_0_0.tga");
  load_tga(&(game->txt[TEXT_MAINSHIP1 - 1]), "pic/sprite_ship_0_1.tga");
  load_tga(&(game->txt[TEXT_MAINSHIP1]), "pic/sprite_ship_0_2.tga");
  load_tga(&(game->txt[TEXT_MAINSHIP1 + 1]), "pic/sprite_ship_0_3.tga");
  load_tga(&(game->txt[TEXT_MAINSHIP1 + 2]), "pic/sprite_ship_0_4.tga");
  load_tga(&(game->txt[TEXT_SUN]), "pic/sun.tga");
  load_tga(&(game->txt[TEXT_PLANET]), "pic/planet.tga");
  load_tga(&(game->txt[TEXT_LASER1]), "pic/laser1.tga");
  load_tga(&(game->txt[TEXT_LASER2]), "pic/laser2.tga");
  load_tga(&(game->txt[ICO_LASER1]), "pic/laser1_ico.tga");
  load_tga(&(game->txt[ICO_LASER2]), "pic/laser2_ico.tga");
  load_tga(&(game->txt[ICO_GUN1]), "pic/minigun1_ico.tga");
  load_tga(&(game->txt[ICO_GUN2]), "pic/minigun2_ico.tga");
  load_tga(&(game->txt[ICO_GUN3]), "pic/minigun3_ico.tga");
  load_tga(&(game->txt[ICO_MISSILE1]), "pic/missile1_ico.tga");
  load_tga(&(game->txt[TEXT_GUN]), "pic/gun.tga");
  load_tga(&(game->txt[TEXT_MISSILE1]), "pic/missile1.tga");
  load_tga(&(game->txt[TEXT_CYCLONE1]), "pic/cyclone.tga");
  load_tga(&(game->txt[ICO_CYCLONE1]), "pic/cyclone_ico.tga");
  load_tga(&(game->txt[TEXT_SHIP1]), "pic/ship_1.tga");
  return;
}

static void     load_part_2(s_game      *game)
{
  load_tga(&(game->txt[TEXT_ASTE_1]), "pic/aste_1.tga");
  load_tga(&(game->txt[TEXT_ASTE_2]), "pic/aste_2.tga");
  load_tga(&(game->txt[TEXT_ASTE_3]), "pic/aste_3.tga");
  load_tga(&(game->txt[TEXT_BOSS_1]), "pic/boss_1.tga");
  load_tga(&(game->txt[TEXT_BOSS_2]), "pic/boss_2.tga");
  load_tga(&(game->txt[TEXT_MAINSHIP2 - 2]), "pic/sprite_ship_1_0.tga");
  load_tga(&(game->txt[TEXT_MAINSHIP2 - 1]), "pic/sprite_ship_1_1.tga");
  load_tga(&(game->txt[TEXT_MAINSHIP2]), "pic/sprite_ship_1_2.tga");
  load_tga(&(game->txt[TEXT_MAINSHIP2 + 1]), "pic/sprite_ship_1_3.tga");
  load_tga(&(game->txt[TEXT_MAINSHIP2 + 2]), "pic/sprite_ship_1_4.tga");
  load_tga(&(game->txt[TEXT_SHIP2]), "pic/ship_2.tga");
  load_tga(&(game->txt[TEXT_SHIP3]), "pic/ship_3.tga");
  load_tga(&(game->txt[TEXT_SHIP4]), "pic/ship_4.tga");
  load_tga(&(game->txt[TEXT_SHIP5]), "pic/ship_5.tga");
  load_tga(&(game->txt[TEXT_SHIP6]), "pic/ship_6.tga");
  load_tga(&(game->txt[TEXT_SHIP7]), "pic/ship_7.tga");
  load_tga(&(game->txt[TEXT_SHIP8]), "pic/ship_8.tga");
  load_tga(&(game->txt[TEXT_SHIP9]), "pic/ship_9.tga");
  load_tga(&(game->txt[TEXT_HUD]), "pic/title.tga");
  load_tga(&(game->txt[TEXT_GAMEOVER]), "pic/gameover.tga");
  return;
}

static void     load_part_3(s_game      *game)
{
  load_tga(&(game->txt[ICO_FAST_SHOT]), "pic/fast_shot_ico.tga");
  load_tga(&(game->txt[ICO_HEAL]), "pic/heal_ico.tga");
  load_tga(&(game->txt[ICO_NONE]), "pic/none_ico.tga");
  load_tga(&(game->txt[ICO_TRI]), "pic/tri_ico.tga");
  load_tga(&(game->txt[ICO_TURBO]), "pic/turbo_ico.tga");
  load_tga(&(game->txt[ICO_NEW]), "pic/new_ico.tga");
  return;
}

int	load_textures(s_game	*game)
{
  load_part_1(game);
  load_part_2(game);
  load_part_3(game);
  return (0);
}
