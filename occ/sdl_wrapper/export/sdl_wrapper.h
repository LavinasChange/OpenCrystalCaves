#ifndef SDL_WRAPPER_H_
#define SDL_WRAPPER_H_

#include <string>
#include <memory>

#include "geometry.h"

class Surface;

struct Color
{
  std::uint8_t red   = 0u;
  std::uint8_t green = 0u;
  std::uint8_t blue  = 0u;
};

class Window
{
 public:
  static std::unique_ptr<Window> create(const std::string& title, geometry::Size size);

  virtual ~Window() = default;

  virtual std::unique_ptr<Surface> get_surface() = 0;
  virtual void refresh() = 0;

  virtual std::unique_ptr<Surface> create_surface(geometry::Size size) = 0;
};

enum class BlitType
{
  CROP,
  SCALE
};

class Surface
{
 public:
  static std::unique_ptr<Surface> from_bmp(const std::string& filename);

  virtual ~Surface() = default;

  virtual int width() const = 0;
  virtual int height() const = 0;

  virtual void blit_surface(const Surface* surface,
                            const geometry::Rectangle& source,
                            const geometry::Rectangle& dest,
                            BlitType blit_type) = 0;
  virtual void fill_rect(const geometry::Rectangle& rect, const Color& color) = 0;
  virtual void render_text(const geometry::Position& pos, const std::string& text, const Color& color) = 0;


};

#endif  // SDL_WRAPPER_H_