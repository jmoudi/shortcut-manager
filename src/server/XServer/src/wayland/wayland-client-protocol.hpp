#pragma once

#include <array>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include <wayland-client.hpp>

struct wl_registry;
struct wl_callback;
struct wl_compositor;
struct wl_shm_pool;
struct wl_shm;
struct wl_buffer;
struct wl_data_offer;
struct wl_data_source;
struct wl_data_device;
struct wl_data_device_manager;
struct wl_shell;
struct wl_shell_surface;
struct wl_surface;
struct wl_seat;
struct wl_pointer;
struct wl_keyboard;
struct wl_touch;
struct wl_output;
struct wl_region;
struct wl_subcompositor;
struct wl_subsurface;

namespace wayland
{
class registry_t;
class callback_t;
class compositor_t;
class shm_pool_t;
class shm_t;
enum class shm_error : uint32_t;
enum class shm_format : uint32_t;
class buffer_t;
class data_offer_t;
enum class data_offer_error : uint32_t;
class data_source_t;
enum class data_source_error : uint32_t;
class data_device_t;
enum class data_device_error : uint32_t;
class data_device_manager_t;
struct data_device_manager_dnd_action;
class shell_t;
enum class shell_error : uint32_t;
class shell_surface_t;
struct shell_surface_resize;
struct shell_surface_transient;
enum class shell_surface_fullscreen_method : uint32_t;
class surface_t;
enum class surface_error : uint32_t;
class seat_t;
struct seat_capability;
class pointer_t;
enum class pointer_error : uint32_t;
enum class pointer_button_state : uint32_t;
enum class pointer_axis : uint32_t;
enum class pointer_axis_source : uint32_t;
class keyboard_t;
enum class keyboard_keymap_format : uint32_t;
enum class keyboard_key_state : uint32_t;
class touch_t;
class output_t;
enum class output_subpixel : uint32_t;
struct output_transform;
struct output_mode;
class region_t;
class subcompositor_t;
enum class subcompositor_error : uint32_t;
class subsurface_t;
enum class subsurface_error : uint32_t;

namespace detail
{
  extern const wl_interface display_interface;
  extern const wl_interface registry_interface;
  extern const wl_interface callback_interface;
  extern const wl_interface compositor_interface;
  extern const wl_interface shm_pool_interface;
  extern const wl_interface shm_interface;
  extern const wl_interface buffer_interface;
  extern const wl_interface data_offer_interface;
  extern const wl_interface data_source_interface;
  extern const wl_interface data_device_interface;
  extern const wl_interface data_device_manager_interface;
  extern const wl_interface shell_interface;
  extern const wl_interface shell_surface_interface;
  extern const wl_interface surface_interface;
  extern const wl_interface seat_interface;
  extern const wl_interface pointer_interface;
  extern const wl_interface keyboard_interface;
  extern const wl_interface touch_interface;
  extern const wl_interface output_interface;
  extern const wl_interface region_interface;
  extern const wl_interface subcompositor_interface;
  extern const wl_interface subsurface_interface;
}

/** \brief global registry object

      The singleton global registry object.  The server has a number of
      global objects that are available to all clients.  These objects
      typically represent an actual object in the server (for example,
      an input device) or they are singleton objects that provide
      extension functionality.

      When a client creates a registry object, the registry object
      will emit a global event for each global currently in the
      registry.  Globals come and go as a result of device or
      monitor hotplugs, reconfiguration or other events, and the
      registry will send out global and global_remove events to
      keep the client up to date with the changes.  To mark the end
      of the initial burst of events, the client can use the
      wl_display.sync request immediately after calling
      wl_display.get_registry.

      A client can bind to a global object by using the bind
      request.  This creates a client-side handle that lets the object
      emit events to the client and lets the client invoke requests on
      the object.
    
*/
class registry_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(uint32_t, std::string, uint32_t)> global;
    std::function<void(uint32_t)> global_remove;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  registry_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  registry_t();
  explicit registry_t(const proxy_t &proxy);
  registry_t(wl_registry *p, wrapper_type t = wrapper_type::standard);

  registry_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_registry*() const;

  /** \brief bind an object to the display
      \return bounded object
      \param name unique numeric name of the object
      \param interface Interface to bind
      \param version Interface version

	Binds a new, client-created object to the server using the
	specified name as the identifier.
      
  */
  proxy_t bind(uint32_t name, proxy_t &interface, uint32_t version);

  /** \brief Minimum protocol version required for the \ref bind function
  */
  static constexpr std::uint32_t bind_since_version = 1;

  /** \brief announce global object
      \param name numeric name of the global object
      \param interface interface implemented by the object
      \param version interface version

	Notify the client of global objects.

	The event notifies the client that a global object with
	the given name is now available, and it implements the
	given version of the given interface.
      
  */
  std::function<void(uint32_t, std::string, uint32_t)> &on_global();

  /** \brief announce removal of global object
      \param name numeric name of the global object

	Notify the client of removed global objects.

	This event notifies the client that the global identified
	by name is no longer available.  If the client bound to
	the global using the bind request, the client should now
	destroy that object.

	The object remains valid and requests to the object will be
	ignored until the client destroys it, to avoid races between
	the global going away and a client sending a request to it.
      
  */
  std::function<void(uint32_t)> &on_global_remove();

};


/** \brief callback object

      Clients can handle the 'done' event to get notified when
      the related request is done.
    
*/
class callback_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(uint32_t)> done;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  callback_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  callback_t();
  explicit callback_t(const proxy_t &proxy);
  callback_t(wl_callback *p, wrapper_type t = wrapper_type::standard);

  callback_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_callback*() const;

  /** \brief done event
      \param callback_data request-specific data for the callback

	Notify the client when the related request is done.
      
  */
  std::function<void(uint32_t)> &on_done();

};


/** \brief the compositor singleton

      A compositor.  This object is a singleton global.  The
      compositor is in charge of combining the contents of multiple
      surfaces into one displayable output.
    
*/
class compositor_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  compositor_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  compositor_t();
  explicit compositor_t(const proxy_t &proxy);
  compositor_t(wl_compositor *p, wrapper_type t = wrapper_type::standard);

  compositor_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_compositor*() const;

  /** \brief create new surface
      \return the new surface

	Ask the compositor to create a new surface.
      
  */
  surface_t create_surface();

  /** \brief Minimum protocol version required for the \ref create_surface function
  */
  static constexpr std::uint32_t create_surface_since_version = 1;

  /** \brief create new region
      \return the new region

	Ask the compositor to create a new region.
      
  */
  region_t create_region();

  /** \brief Minimum protocol version required for the \ref create_region function
  */
  static constexpr std::uint32_t create_region_since_version = 1;

};


/** \brief a shared memory pool

      The wl_shm_pool object encapsulates a piece of memory shared
      between the compositor and client.  Through the wl_shm_pool
      object, the client can allocate shared memory wl_buffer objects.
      All objects created through the same pool share the same
      underlying mapped memory. Reusing the mapped memory avoids the
      setup/teardown overhead and is useful when interactively resizing
      a surface or for many small buffers.
    
*/
class shm_pool_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  shm_pool_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  shm_pool_t();
  explicit shm_pool_t(const proxy_t &proxy);
  shm_pool_t(wl_shm_pool *p, wrapper_type t = wrapper_type::standard);

  shm_pool_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_shm_pool*() const;

  /** \brief create a buffer from the pool
      \return buffer to create
      \param offset buffer byte offset within the pool
      \param width buffer width, in pixels
      \param height buffer height, in pixels
      \param stride number of bytes from the beginning of one row to the beginning of the next row
      \param format buffer pixel format

	Create a wl_buffer object from the pool.

	The buffer is created offset bytes into the pool and has
	width and height as specified.  The stride argument specifies
	the number of bytes from the beginning of one row to the beginning
	of the next.  The format is the pixel format of the buffer and
	must be one of those advertised through the wl_shm.format event.

	A buffer will keep a reference to the pool it was created from
	so it is valid to destroy the pool immediately after creating
	a buffer from it.
      
  */
  buffer_t create_buffer(int32_t offset, int32_t width, int32_t height, int32_t stride, shm_format format);

  /** \brief Minimum protocol version required for the \ref create_buffer function
  */
  static constexpr std::uint32_t create_buffer_since_version = 1;

  /** \brief change the size of the pool mapping
      \param size new size of the pool, in bytes

	This request will cause the server to remap the backing memory
	for the pool from the file descriptor passed when the pool was
	created, but using the new size.  This request can only be
	used to make the pool bigger.
      
  */
  void resize(int32_t size);

  /** \brief Minimum protocol version required for the \ref resize function
  */
  static constexpr std::uint32_t resize_since_version = 1;

};


/** \brief shared memory support

      A singleton global object that provides support for shared
      memory.

      Clients can create wl_shm_pool objects using the create_pool
      request.

      At connection setup time, the wl_shm object emits one or more
      format events to inform clients about the valid pixel formats
      that can be used for buffers.
    
*/
class shm_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(shm_format)> format;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  shm_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  shm_t();
  explicit shm_t(const proxy_t &proxy);
  shm_t(wl_shm *p, wrapper_type t = wrapper_type::standard);

  shm_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_shm*() const;

  /** \brief create a shm pool
      \return pool to create
      \param fd file descriptor for the pool
      \param size pool size, in bytes

	Create a new wl_shm_pool object.

	The pool can be used to create shared memory based buffer
	objects.  The server will mmap size bytes of the passed file
	descriptor, to use as backing memory for the pool.
      
  */
  shm_pool_t create_pool(int fd, int32_t size);

  /** \brief Minimum protocol version required for the \ref create_pool function
  */
  static constexpr std::uint32_t create_pool_since_version = 1;

  /** \brief pixel format description
      \param format buffer pixel format

	Informs the client about a valid pixel format that
	can be used for buffers. Known formats include
	argb8888 and xrgb8888.
      
  */
  std::function<void(shm_format)> &on_format();

};

/** \brief wl_shm error values

	These errors can be emitted in response to wl_shm requests.
      
  */
enum class shm_error : uint32_t
  {
  /** \brief buffer format is not known */
  invalid_format = 0,
  /** \brief invalid size or stride during pool or buffer creation */
  invalid_stride = 1,
  /** \brief mmapping the file descriptor failed */
  invalid_fd = 2
};

/** \brief pixel formats

	This describes the memory layout of an individual pixel.

	All renderers should support argb8888 and xrgb8888 but any other
	formats are optional and may not be supported by the particular
	renderer in use.

	The drm format codes match the macros defined in drm_fourcc.h.
	The formats actually supported by the compositor will be
	reported by the format event.
      
  */
enum class shm_format : uint32_t
  {
  /** \brief 32-bit ARGB format, [31:0] A:R:G:B 8:8:8:8 little endian */
  argb8888 = 0,
  /** \brief 32-bit RGB format, [31:0] x:R:G:B 8:8:8:8 little endian */
  xrgb8888 = 1,
  /** \brief 8-bit color index format, [7:0] C */
  c8 = 0x20203843,
  /** \brief 8-bit RGB format, [7:0] R:G:B 3:3:2 */
  rgb332 = 0x38424752,
  /** \brief 8-bit BGR format, [7:0] B:G:R 2:3:3 */
  bgr233 = 0x38524742,
  /** \brief 16-bit xRGB format, [15:0] x:R:G:B 4:4:4:4 little endian */
  xrgb4444 = 0x32315258,
  /** \brief 16-bit xBGR format, [15:0] x:B:G:R 4:4:4:4 little endian */
  xbgr4444 = 0x32314258,
  /** \brief 16-bit RGBx format, [15:0] R:G:B:x 4:4:4:4 little endian */
  rgbx4444 = 0x32315852,
  /** \brief 16-bit BGRx format, [15:0] B:G:R:x 4:4:4:4 little endian */
  bgrx4444 = 0x32315842,
  /** \brief 16-bit ARGB format, [15:0] A:R:G:B 4:4:4:4 little endian */
  argb4444 = 0x32315241,
  /** \brief 16-bit ABGR format, [15:0] A:B:G:R 4:4:4:4 little endian */
  abgr4444 = 0x32314241,
  /** \brief 16-bit RBGA format, [15:0] R:G:B:A 4:4:4:4 little endian */
  rgba4444 = 0x32314152,
  /** \brief 16-bit BGRA format, [15:0] B:G:R:A 4:4:4:4 little endian */
  bgra4444 = 0x32314142,
  /** \brief 16-bit xRGB format, [15:0] x:R:G:B 1:5:5:5 little endian */
  xrgb1555 = 0x35315258,
  /** \brief 16-bit xBGR 1555 format, [15:0] x:B:G:R 1:5:5:5 little endian */
  xbgr1555 = 0x35314258,
  /** \brief 16-bit RGBx 5551 format, [15:0] R:G:B:x 5:5:5:1 little endian */
  rgbx5551 = 0x35315852,
  /** \brief 16-bit BGRx 5551 format, [15:0] B:G:R:x 5:5:5:1 little endian */
  bgrx5551 = 0x35315842,
  /** \brief 16-bit ARGB 1555 format, [15:0] A:R:G:B 1:5:5:5 little endian */
  argb1555 = 0x35315241,
  /** \brief 16-bit ABGR 1555 format, [15:0] A:B:G:R 1:5:5:5 little endian */
  abgr1555 = 0x35314241,
  /** \brief 16-bit RGBA 5551 format, [15:0] R:G:B:A 5:5:5:1 little endian */
  rgba5551 = 0x35314152,
  /** \brief 16-bit BGRA 5551 format, [15:0] B:G:R:A 5:5:5:1 little endian */
  bgra5551 = 0x35314142,
  /** \brief 16-bit RGB 565 format, [15:0] R:G:B 5:6:5 little endian */
  rgb565 = 0x36314752,
  /** \brief 16-bit BGR 565 format, [15:0] B:G:R 5:6:5 little endian */
  bgr565 = 0x36314742,
  /** \brief 24-bit RGB format, [23:0] R:G:B little endian */
  rgb888 = 0x34324752,
  /** \brief 24-bit BGR format, [23:0] B:G:R little endian */
  bgr888 = 0x34324742,
  /** \brief 32-bit xBGR format, [31:0] x:B:G:R 8:8:8:8 little endian */
  xbgr8888 = 0x34324258,
  /** \brief 32-bit RGBx format, [31:0] R:G:B:x 8:8:8:8 little endian */
  rgbx8888 = 0x34325852,
  /** \brief 32-bit BGRx format, [31:0] B:G:R:x 8:8:8:8 little endian */
  bgrx8888 = 0x34325842,
  /** \brief 32-bit ABGR format, [31:0] A:B:G:R 8:8:8:8 little endian */
  abgr8888 = 0x34324241,
  /** \brief 32-bit RGBA format, [31:0] R:G:B:A 8:8:8:8 little endian */
  rgba8888 = 0x34324152,
  /** \brief 32-bit BGRA format, [31:0] B:G:R:A 8:8:8:8 little endian */
  bgra8888 = 0x34324142,
  /** \brief 32-bit xRGB format, [31:0] x:R:G:B 2:10:10:10 little endian */
  xrgb2101010 = 0x30335258,
  /** \brief 32-bit xBGR format, [31:0] x:B:G:R 2:10:10:10 little endian */
  xbgr2101010 = 0x30334258,
  /** \brief 32-bit RGBx format, [31:0] R:G:B:x 10:10:10:2 little endian */
  rgbx1010102 = 0x30335852,
  /** \brief 32-bit BGRx format, [31:0] B:G:R:x 10:10:10:2 little endian */
  bgrx1010102 = 0x30335842,
  /** \brief 32-bit ARGB format, [31:0] A:R:G:B 2:10:10:10 little endian */
  argb2101010 = 0x30335241,
  /** \brief 32-bit ABGR format, [31:0] A:B:G:R 2:10:10:10 little endian */
  abgr2101010 = 0x30334241,
  /** \brief 32-bit RGBA format, [31:0] R:G:B:A 10:10:10:2 little endian */
  rgba1010102 = 0x30334152,
  /** \brief 32-bit BGRA format, [31:0] B:G:R:A 10:10:10:2 little endian */
  bgra1010102 = 0x30334142,
  /** \brief packed YCbCr format, [31:0] Cr0:Y1:Cb0:Y0 8:8:8:8 little endian */
  yuyv = 0x56595559,
  /** \brief packed YCbCr format, [31:0] Cb0:Y1:Cr0:Y0 8:8:8:8 little endian */
  yvyu = 0x55595659,
  /** \brief packed YCbCr format, [31:0] Y1:Cr0:Y0:Cb0 8:8:8:8 little endian */
  uyvy = 0x59565955,
  /** \brief packed YCbCr format, [31:0] Y1:Cb0:Y0:Cr0 8:8:8:8 little endian */
  vyuy = 0x59555956,
  /** \brief packed AYCbCr format, [31:0] A:Y:Cb:Cr 8:8:8:8 little endian */
  ayuv = 0x56555941,
  /** \brief 2 plane YCbCr Cr:Cb format, 2x2 subsampled Cr:Cb plane */
  nv12 = 0x3231564e,
  /** \brief 2 plane YCbCr Cb:Cr format, 2x2 subsampled Cb:Cr plane */
  nv21 = 0x3132564e,
  /** \brief 2 plane YCbCr Cr:Cb format, 2x1 subsampled Cr:Cb plane */
  nv16 = 0x3631564e,
  /** \brief 2 plane YCbCr Cb:Cr format, 2x1 subsampled Cb:Cr plane */
  nv61 = 0x3136564e,
  /** \brief 3 plane YCbCr format, 4x4 subsampled Cb (1) and Cr (2) planes */
  yuv410 = 0x39565559,
  /** \brief 3 plane YCbCr format, 4x4 subsampled Cr (1) and Cb (2) planes */
  yvu410 = 0x39555659,
  /** \brief 3 plane YCbCr format, 4x1 subsampled Cb (1) and Cr (2) planes */
  yuv411 = 0x31315559,
  /** \brief 3 plane YCbCr format, 4x1 subsampled Cr (1) and Cb (2) planes */
  yvu411 = 0x31315659,
  /** \brief 3 plane YCbCr format, 2x2 subsampled Cb (1) and Cr (2) planes */
  yuv420 = 0x32315559,
  /** \brief 3 plane YCbCr format, 2x2 subsampled Cr (1) and Cb (2) planes */
  yvu420 = 0x32315659,
  /** \brief 3 plane YCbCr format, 2x1 subsampled Cb (1) and Cr (2) planes */
  yuv422 = 0x36315559,
  /** \brief 3 plane YCbCr format, 2x1 subsampled Cr (1) and Cb (2) planes */
  yvu422 = 0x36315659,
  /** \brief 3 plane YCbCr format, non-subsampled Cb (1) and Cr (2) planes */
  yuv444 = 0x34325559,
  /** \brief 3 plane YCbCr format, non-subsampled Cr (1) and Cb (2) planes */
  yvu444 = 0x34325659
};


/** \brief content for a wl_surface

      A buffer provides the content for a wl_surface. Buffers are
      created through factory interfaces such as wl_drm, wl_shm or
      similar. It has a width and a height and can be attached to a
      wl_surface, but the mechanism by which a client provides and
      updates the contents is defined by the buffer factory interface.
    
*/
class buffer_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void()> release;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  buffer_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  buffer_t();
  explicit buffer_t(const proxy_t &proxy);
  buffer_t(wl_buffer *p, wrapper_type t = wrapper_type::standard);

  buffer_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_buffer*() const;

  /** \brief compositor releases buffer

	Sent when this wl_buffer is no longer used by the compositor.
	The client is now free to reuse or destroy this buffer and its
	backing storage.

	If a client receives a release event before the frame callback
	requested in the same wl_surface.commit that attaches this
	wl_buffer to a surface, then the client is immediately free to
	reuse the buffer and its backing storage, and does not need a
	second buffer for the next surface content update. Typically
	this is possible, when the compositor maintains a copy of the
	wl_surface contents, e.g. as a GL texture. This is an important
	optimization for GL(ES) compositors with wl_shm clients.
      
  */
  std::function<void()> &on_release();

};


/** \brief offer to transfer data

      A wl_data_offer represents a piece of data offered for transfer
      by another client (the source client).  It is used by the
      copy-and-paste and drag-and-drop mechanisms.  The offer
      describes the different mime types that the data can be
      converted to and provides the mechanism for transferring the
      data directly from the source client.
    
*/
class data_offer_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(std::string)> offer;
    std::function<void(data_device_manager_dnd_action)> source_actions;
    std::function<void(data_device_manager_dnd_action)> action;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  data_offer_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  data_offer_t();
  explicit data_offer_t(const proxy_t &proxy);
  data_offer_t(wl_data_offer *p, wrapper_type t = wrapper_type::standard);

  data_offer_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_data_offer*() const;

  /** \brief accept one of the offered mime types
      \param serial serial number of the accept request
      \param mime_type mime type accepted by the client

	Indicate that the client can accept the given mime type, or
	NULL for not accepted.

	For objects of version 2 or older, this request is used by the
	client to give feedback whether the client can receive the given
	mime type, or NULL if none is accepted; the feedback does not
	determine whether the drag-and-drop operation succeeds or not.

	For objects of version 3 or newer, this request determines the
	final result of the drag-and-drop operation. If the end result
	is that no mime types were accepted, the drag-and-drop operation
	will be cancelled and the corresponding drag source will receive
	wl_data_source.cancelled. Clients may still use this event in
	conjunction with wl_data_source.action for feedback.
      
  */
  void accept(uint32_t serial, std::string mime_type);

  /** \brief Minimum protocol version required for the \ref accept function
  */
  static constexpr std::uint32_t accept_since_version = 1;

  /** \brief request that the data is transferred
      \param mime_type mime type desired by receiver
      \param fd file descriptor for data transfer

	To transfer the offered data, the client issues this request
	and indicates the mime type it wants to receive.  The transfer
	happens through the passed file descriptor (typically created
	with the pipe system call).  The source client writes the data
	in the mime type representation requested and then closes the
	file descriptor.

	The receiving client reads from the read end of the pipe until
	EOF and then closes its end, at which point the transfer is
	complete.

	This request may happen multiple times for different mime types,
	both before and after wl_data_device.drop. Drag-and-drop destination
	clients may preemptively fetch data or examine it more closely to
	determine acceptance.
      
  */
  void receive(std::string mime_type, int fd);

  /** \brief Minimum protocol version required for the \ref receive function
  */
  static constexpr std::uint32_t receive_since_version = 1;

  /** \brief the offer will no longer be used

	Notifies the compositor that the drag destination successfully
	finished the drag-and-drop operation.

	Upon receiving this request, the compositor will emit
	wl_data_source.dnd_finished on the drag source client.

	It is a client error to perform other requests than
	wl_data_offer.destroy after this one. It is also an error to perform
	this request after a NULL mime type has been set in
	wl_data_offer.accept or no action was received through
	wl_data_offer.action.
      
  */
  void finish();

  /** \brief Minimum protocol version required for the \ref finish function
  */
  static constexpr std::uint32_t finish_since_version = 3;

  /** \brief Check whether the \ref finish function is available with
      the currently bound version of the protocol
  */
  bool can_finish() const;

  /** \brief set the available/preferred drag-and-drop actions
      \param dnd_actions actions supported by the destination client
      \param preferred_action action preferred by the destination client

	Sets the actions that the destination side client supports for
	this operation. This request may trigger the emission of
	wl_data_source.action and wl_data_offer.action events if the compositor
	needs to change the selected action.

	This request can be called multiple times throughout the
	drag-and-drop operation, typically in response to wl_data_device.enter
	or wl_data_device.motion events.

	This request determines the final result of the drag-and-drop
	operation. If the end result is that no action is accepted,
	the drag source will receive wl_drag_source.cancelled.

	The dnd_actions argument must contain only values expressed in the
	wl_data_device_manager.dnd_actions enum, and the preferred_action
	argument must only contain one of those values set, otherwise it
	will result in a protocol error.

	While managing an "ask" action, the destination drag-and-drop client
	may perform further wl_data_offer.receive requests, and is expected
	to perform one last wl_data_offer.set_actions request with a preferred
	action other than "ask" (and optionally wl_data_offer.accept) before
	requesting wl_data_offer.finish, in order to convey the action selected
	by the user. If the preferred action is not in the
	wl_data_offer.source_actions mask, an error will be raised.

	If the "ask" action is dismissed (e.g. user cancellation), the client
	is expected to perform wl_data_offer.destroy right away.

	This request can only be made on drag-and-drop offers, a protocol error
	will be raised otherwise.
      
  */
  void set_actions(data_device_manager_dnd_action dnd_actions, data_device_manager_dnd_action preferred_action);

  /** \brief Minimum protocol version required for the \ref set_actions function
  */
  static constexpr std::uint32_t set_actions_since_version = 3;

  /** \brief Check whether the \ref set_actions function is available with
      the currently bound version of the protocol
  */
  bool can_set_actions() const;

  /** \brief advertise offered mime type
      \param mime_type offered mime type

	Sent immediately after creating the wl_data_offer object.  One
	event per offered mime type.
      
  */
  std::function<void(std::string)> &on_offer();

  /** \brief notify the source-side available actions
      \param source_actions actions offered by the data source

	This event indicates the actions offered by the data source. It
	will be sent right after wl_data_device.enter, or anytime the source
	side changes its offered actions through wl_data_source.set_actions.
      
  */
  std::function<void(data_device_manager_dnd_action)> &on_source_actions();

  /** \brief notify the selected action
      \param dnd_action action selected by the compositor

	This event indicates the action selected by the compositor after
	matching the source/destination side actions. Only one action (or
	none) will be offered here.

	This event can be emitted multiple times during the drag-and-drop
	operation in response to destination side action changes through
	wl_data_offer.set_actions.

	This event will no longer be emitted after wl_data_device.drop
	happened on the drag-and-drop destination, the client must
	honor the last action received, or the last preferred one set
	through wl_data_offer.set_actions when handling an "ask" action.

	Compositors may also change the selected action on the fly, mainly
	in response to keyboard modifier changes during the drag-and-drop
	operation.

	The most recent action received is always the valid one. Prior to
	receiving wl_data_device.drop, the chosen action may change (e.g.
	due to keyboard modifiers being pressed). At the time of receiving
	wl_data_device.drop the drag-and-drop destination must honor the
	last action received.

	Action changes may still happen after wl_data_device.drop,
	especially on "ask" actions, where the drag-and-drop destination
	may choose another action afterwards. Action changes happening
	at this stage are always the result of inter-client negotiation, the
	compositor shall no longer be able to induce a different action.

	Upon "ask" actions, it is expected that the drag-and-drop destination
	may potentially choose a different action and/or mime type,
	based on wl_data_offer.source_actions and finally chosen by the
	user (e.g. popping up a menu with the available options). The
	final wl_data_offer.set_actions and wl_data_offer.accept requests
	must happen before the call to wl_data_offer.finish.
      
  */
  std::function<void(data_device_manager_dnd_action)> &on_action();

};

/** \brief 

  */
enum class data_offer_error : uint32_t
  {
  /** \brief finish request was called untimely */
  invalid_finish = 0,
  /** \brief action mask contains invalid values */
  invalid_action_mask = 1,
  /** \brief action argument has an invalid value */
  invalid_action = 2,
  /** \brief offer doesn't accept this request */
  invalid_offer = 3
};


/** \brief offer to transfer data

      The wl_data_source object is the source side of a wl_data_offer.
      It is created by the source client in a data transfer and
      provides a way to describe the offered data and a way to respond
      to requests to transfer the data.
    
*/
class data_source_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(std::string)> target;
    std::function<void(std::string, int)> send;
    std::function<void()> cancelled;
    std::function<void()> dnd_drop_performed;
    std::function<void()> dnd_finished;
    std::function<void(data_device_manager_dnd_action)> action;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  data_source_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  data_source_t();
  explicit data_source_t(const proxy_t &proxy);
  data_source_t(wl_data_source *p, wrapper_type t = wrapper_type::standard);

  data_source_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_data_source*() const;

  /** \brief add an offered mime type
      \param mime_type mime type offered by the data source

	This request adds a mime type to the set of mime types
	advertised to targets.  Can be called several times to offer
	multiple types.
      
  */
  void offer(std::string mime_type);

  /** \brief Minimum protocol version required for the \ref offer function
  */
  static constexpr std::uint32_t offer_since_version = 1;

  /** \brief set the available drag-and-drop actions
      \param dnd_actions actions supported by the data source

	Sets the actions that the source side client supports for this
	operation. This request may trigger wl_data_source.action and
	wl_data_offer.action events if the compositor needs to change the
	selected action.

	The dnd_actions argument must contain only values expressed in the
	wl_data_device_manager.dnd_actions enum, otherwise it will result
	in a protocol error.

	This request must be made once only, and can only be made on sources
	used in drag-and-drop, so it must be performed before
	wl_data_device.start_drag. Attempting to use the source other than
	for drag-and-drop will raise a protocol error.
      
  */
  void set_actions(data_device_manager_dnd_action dnd_actions);

  /** \brief Minimum protocol version required for the \ref set_actions function
  */
  static constexpr std::uint32_t set_actions_since_version = 3;

  /** \brief Check whether the \ref set_actions function is available with
      the currently bound version of the protocol
  */
  bool can_set_actions() const;

  /** \brief a target accepts an offered mime type
      \param mime_type mime type accepted by the target

	Sent when a target accepts pointer_focus or motion events.  If
	a target does not accept any of the offered types, type is NULL.

	Used for feedback during drag-and-drop.
      
  */
  std::function<void(std::string)> &on_target();

  /** \brief send the data
      \param mime_type mime type for the data
      \param fd file descriptor for the data

	Request for data from the client.  Send the data as the
	specified mime type over the passed file descriptor, then
	close it.
      
  */
  std::function<void(std::string, int)> &on_send();

  /** \brief selection was cancelled

	This data source is no longer valid. There are several reasons why
	this could happen:

	- The data source has been replaced by another data source.
	- The drag-and-drop operation was performed, but the drop destination
	  did not accept any of the mime types offered through
	  wl_data_source.target.
	- The drag-and-drop operation was performed, but the drop destination
	  did not select any of the actions present in the mask offered through
	  wl_data_source.action.
	- The drag-and-drop operation was performed but didn't happen over a
	  surface.
	- The compositor cancelled the drag-and-drop operation (e.g. compositor
	  dependent timeouts to avoid stale drag-and-drop transfers).

	The client should clean up and destroy this data source.

	For objects of version 2 or older, wl_data_source.cancelled will
	only be emitted if the data source was replaced by another data
	source.
      
  */
  std::function<void()> &on_cancelled();

  /** \brief the drag-and-drop operation physically finished

	The user performed the drop action. This event does not indicate
	acceptance, wl_data_source.cancelled may still be emitted afterwards
	if the drop destination does not accept any mime type.

	However, this event might however not be received if the compositor
	cancelled the drag-and-drop operation before this event could happen.

	Note that the data_source may still be used in the future and should
	not be destroyed here.
      
  */
  std::function<void()> &on_dnd_drop_performed();

  /** \brief the drag-and-drop operation concluded

	The drop destination finished interoperating with this data
	source, so the client is now free to destroy this data source and
	free all associated data.

	If the action used to perform the operation was "move", the
	source can now delete the transferred data.
      
  */
  std::function<void()> &on_dnd_finished();

  /** \brief notify the selected action
      \param dnd_action action selected by the compositor

	This event indicates the action selected by the compositor after
	matching the source/destination side actions. Only one action (or
	none) will be offered here.

	This event can be emitted multiple times during the drag-and-drop
	operation, mainly in response to destination side changes through
	wl_data_offer.set_actions, and as the data device enters/leaves
	surfaces.

	It is only possible to receive this event after
	wl_data_source.dnd_drop_performed if the drag-and-drop operation
	ended in an "ask" action, in which case the final wl_data_source.action
	event will happen immediately before wl_data_source.dnd_finished.

	Compositors may also change the selected action on the fly, mainly
	in response to keyboard modifier changes during the drag-and-drop
	operation.

	The most recent action received is always the valid one. The chosen
	action may change alongside negotiation (e.g. an "ask" action can turn
	into a "move" operation), so the effects of the final action must
	always be applied in wl_data_offer.dnd_finished.

	Clients can trigger cursor surface changes from this point, so
	they reflect the current action.
      
  */
  std::function<void(data_device_manager_dnd_action)> &on_action();

};

/** \brief 

  */
enum class data_source_error : uint32_t
  {
  /** \brief action mask contains invalid values */
  invalid_action_mask = 0,
  /** \brief source doesn't accept this request */
  invalid_source = 1
};


/** \brief data transfer device

      There is one wl_data_device per seat which can be obtained
      from the global wl_data_device_manager singleton.

      A wl_data_device provides access to inter-client data transfer
      mechanisms such as copy-and-paste and drag-and-drop.
    
*/
class data_device_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(data_offer_t)> data_offer;
    std::function<void(uint32_t, surface_t, double, double, data_offer_t)> enter;
    std::function<void()> leave;
    std::function<void(uint32_t, double, double)> motion;
    std::function<void()> drop;
    std::function<void(data_offer_t)> selection;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  data_device_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  data_device_t();
  explicit data_device_t(const proxy_t &proxy);
  data_device_t(wl_data_device *p, wrapper_type t = wrapper_type::standard);

  data_device_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_data_device*() const;

  /** \brief start drag-and-drop operation
      \param source data source for the eventual transfer
      \param origin surface where the drag originates
      \param icon drag-and-drop icon surface
      \param serial serial number of the implicit grab on the origin

	This request asks the compositor to start a drag-and-drop
	operation on behalf of the client.

	The source argument is the data source that provides the data
	for the eventual data transfer. If source is NULL, enter, leave
	and motion events are sent only to the client that initiated the
	drag and the client is expected to handle the data passing
	internally.

	The origin surface is the surface where the drag originates and
	the client must have an active implicit grab that matches the
	serial.

	The icon surface is an optional (can be NULL) surface that
	provides an icon to be moved around with the cursor.  Initially,
	the top-left corner of the icon surface is placed at the cursor
	hotspot, but subsequent wl_surface.attach request can move the
	relative position. Attach requests must be confirmed with
	wl_surface.commit as usual. The icon surface is given the role of
	a drag-and-drop icon. If the icon surface already has another role,
	it raises a protocol error.

	The current and pending input regions of the icon wl_surface are
	cleared, and wl_surface.set_input_region is ignored until the
	wl_surface is no longer used as the icon surface. When the use
	as an icon ends, the current and pending input regions become
	undefined, and the wl_surface is unmapped.
      
  */
  void start_drag(data_source_t source, surface_t origin, surface_t icon, uint32_t serial);

  /** \brief Minimum protocol version required for the \ref start_drag function
  */
  static constexpr std::uint32_t start_drag_since_version = 1;

  /** \brief copy data to the selection
      \param source data source for the selection
      \param serial serial number of the event that triggered this request

	This request asks the compositor to set the selection
	to the data from the source on behalf of the client.

	To unset the selection, set the source to NULL.
      
  */
  void set_selection(data_source_t source, uint32_t serial);

  /** \brief Minimum protocol version required for the \ref set_selection function
  */
  static constexpr std::uint32_t set_selection_since_version = 1;

  /** \brief destroy data device

	This request destroys the data device.
      
  */
  void release();

  /** \brief Minimum protocol version required for the \ref release function
  */
  static constexpr std::uint32_t release_since_version = 2;

  /** \brief Check whether the \ref release function is available with
      the currently bound version of the protocol
  */
  bool can_release() const;

  /** \brief introduce a new wl_data_offer
      \param id the new data_offer object

	The data_offer event introduces a new wl_data_offer object,
	which will subsequently be used in either the
	data_device.enter event (for drag-and-drop) or the
	data_device.selection event (for selections).  Immediately
	following the data_device_data_offer event, the new data_offer
	object will send out data_offer.offer events to describe the
	mime types it offers.
      
  */
  std::function<void(data_offer_t)> &on_data_offer();

  /** \brief initiate drag-and-drop session
      \param serial serial number of the enter event
      \param surface client surface entered
      \param x surface-local x coordinate
      \param y surface-local y coordinate
      \param id source data_offer object

	This event is sent when an active drag-and-drop pointer enters
	a surface owned by the client.  The position of the pointer at
	enter time is provided by the x and y arguments, in surface-local
	coordinates.
      
  */
  std::function<void(uint32_t, surface_t, double, double, data_offer_t)> &on_enter();

  /** \brief end drag-and-drop session

	This event is sent when the drag-and-drop pointer leaves the
	surface and the session ends.  The client must destroy the
	wl_data_offer introduced at enter time at this point.
      
  */
  std::function<void()> &on_leave();

  /** \brief drag-and-drop session motion
      \param time timestamp with millisecond granularity
      \param x surface-local x coordinate
      \param y surface-local y coordinate

	This event is sent when the drag-and-drop pointer moves within
	the currently focused surface. The new position of the pointer
	is provided by the x and y arguments, in surface-local
	coordinates.
      
  */
  std::function<void(uint32_t, double, double)> &on_motion();

  /** \brief end drag-and-drop session successfully

	The event is sent when a drag-and-drop operation is ended
	because the implicit grab is removed.

	The drag-and-drop destination is expected to honor the last action
	received through wl_data_offer.action, if the resulting action is
	"copy" or "move", the destination can still perform
	wl_data_offer.receive requests, and is expected to end all
	transfers with a wl_data_offer.finish request.

	If the resulting action is "ask", the action will not be considered
	final. The drag-and-drop destination is expected to perform one last
	wl_data_offer.set_actions request, or wl_data_offer.destroy in order
	to cancel the operation.
      
  */
  std::function<void()> &on_drop();

  /** \brief advertise new selection
      \param id selection data_offer object

	The selection event is sent out to notify the client of a new
	wl_data_offer for the selection for this device.  The
	data_device.data_offer and the data_offer.offer events are
	sent out immediately before this event to introduce the data
	offer object.  The selection event is sent to a client
	immediately before receiving keyboard focus and when a new
	selection is set while the client has keyboard focus.  The
	data_offer is valid until a new data_offer or NULL is received
	or until the client loses keyboard focus.  The client must
	destroy the previous selection data_offer, if any, upon receiving
	this event.
      
  */
  std::function<void(data_offer_t)> &on_selection();

};

/** \brief 

  */
enum class data_device_error : uint32_t
  {
  /** \brief given wl_surface has another role */
  role = 0
};


/** \brief data transfer interface

      The wl_data_device_manager is a singleton global object that
      provides access to inter-client data transfer mechanisms such as
      copy-and-paste and drag-and-drop.  These mechanisms are tied to
      a wl_seat and this interface lets a client get a wl_data_device
      corresponding to a wl_seat.

      Depending on the version bound, the objects created from the bound
      wl_data_device_manager object will have different requirements for
      functioning properly. See wl_data_source.set_actions,
      wl_data_offer.accept and wl_data_offer.finish for details.
    
*/
class data_device_manager_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  data_device_manager_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  data_device_manager_t();
  explicit data_device_manager_t(const proxy_t &proxy);
  data_device_manager_t(wl_data_device_manager *p, wrapper_type t = wrapper_type::standard);

  data_device_manager_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_data_device_manager*() const;

  /** \brief create a new data source
      \return data source to create

	Create a new data source.
      
  */
  data_source_t create_data_source();

  /** \brief Minimum protocol version required for the \ref create_data_source function
  */
  static constexpr std::uint32_t create_data_source_since_version = 1;

  /** \brief create a new data device
      \return data device to create
      \param seat seat associated with the data device

	Create a new data device for a given seat.
      
  */
  data_device_t get_data_device(seat_t seat);

  /** \brief Minimum protocol version required for the \ref get_data_device function
  */
  static constexpr std::uint32_t get_data_device_since_version = 1;

};

/** \brief drag and drop actions

	This is a bitmask of the available/preferred actions in a
	drag-and-drop operation.

	In the compositor, the selected action is a result of matching the
	actions offered by the source and destination sides.  "action" events
	with a "none" action will be sent to both source and destination if
	there is no match. All further checks will effectively happen on
	(source actions ∩ destination actions).

	In addition, compositors may also pick different actions in
	reaction to key modifiers being pressed. One common design that
	is used in major toolkits (and the behavior recommended for
	compositors) is:

	- If no modifiers are pressed, the first match (in bit order)
	  will be used.
	- Pressing Shift selects "move", if enabled in the mask.
	- Pressing Control selects "copy", if enabled in the mask.

	Behavior beyond that is considered implementation-dependent.
	Compositors may for example bind other modifiers (like Alt/Meta)
	or drags initiated with other buttons than BTN_LEFT to specific
	actions (e.g. "ask").
      
  */
struct data_device_manager_dnd_action : public detail::bitfield<3, 6>
{
  data_device_manager_dnd_action(const detail::bitfield<3, 6> &b)
    : detail::bitfield<3, 6>(b) {}
  data_device_manager_dnd_action(const uint32_t value)
    : detail::bitfield<3, 6>(value) {}
  /** \brief no action */
  static const detail::bitfield<3, 6> none;
  /** \brief copy action */
  static const detail::bitfield<3, 6> copy;
  /** \brief move action */
  static const detail::bitfield<3, 6> move;
  /** \brief ask action */
  static const detail::bitfield<3, 6> ask;
};


/** \brief create desktop-style surfaces

      This interface is implemented by servers that provide
      desktop-style user interfaces.

      It allows clients to associate a wl_shell_surface with
      a basic surface.

      Note! This protocol is deprecated and not intended for production use.
      For desktop-style user interfaces, use xdg_shell.
    
*/
class shell_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  shell_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  shell_t();
  explicit shell_t(const proxy_t &proxy);
  shell_t(wl_shell *p, wrapper_type t = wrapper_type::standard);

  shell_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_shell*() const;

  /** \brief create a shell surface from a surface
      \return shell surface to create
      \param surface surface to be given the shell surface role

	Create a shell surface for an existing surface. This gives
	the wl_surface the role of a shell surface. If the wl_surface
	already has another role, it raises a protocol error.

	Only one shell surface can be associated with a given surface.
      
  */
  shell_surface_t get_shell_surface(surface_t surface);

  /** \brief Minimum protocol version required for the \ref get_shell_surface function
  */
  static constexpr std::uint32_t get_shell_surface_since_version = 1;

};

/** \brief 

  */
enum class shell_error : uint32_t
  {
  /** \brief given wl_surface has another role */
  role = 0
};


/** \brief desktop-style metadata interface

      An interface that may be implemented by a wl_surface, for
      implementations that provide a desktop-style user interface.

      It provides requests to treat surfaces like toplevel, fullscreen
      or popup windows, move, resize or maximize them, associate
      metadata like title and class, etc.

      On the server side the object is automatically destroyed when
      the related wl_surface is destroyed. On the client side,
      wl_shell_surface_destroy() must be called before destroying
      the wl_surface object.
    
*/
class shell_surface_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(uint32_t)> ping;
    std::function<void(shell_surface_resize, int32_t, int32_t)> configure;
    std::function<void()> popup_done;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  shell_surface_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  shell_surface_t();
  explicit shell_surface_t(const proxy_t &proxy);
  shell_surface_t(wl_shell_surface *p, wrapper_type t = wrapper_type::standard);

  shell_surface_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_shell_surface*() const;

  /** \brief respond to a ping event
      \param serial serial number of the ping event

	A client must respond to a ping event with a pong request or
	the client may be deemed unresponsive.
      
  */
  void pong(uint32_t serial);

  /** \brief Minimum protocol version required for the \ref pong function
  */
  static constexpr std::uint32_t pong_since_version = 1;

  /** \brief start an interactive move
      \param seat seat whose pointer is used
      \param serial serial number of the implicit grab on the pointer

	Start a pointer-driven move of the surface.

	This request must be used in response to a button press event.
	The server may ignore move requests depending on the state of
	the surface (e.g. fullscreen or maximized).
      
  */
  void move(seat_t seat, uint32_t serial);

  /** \brief Minimum protocol version required for the \ref move function
  */
  static constexpr std::uint32_t move_since_version = 1;

  /** \brief start an interactive resize
      \param seat seat whose pointer is used
      \param serial serial number of the implicit grab on the pointer
      \param edges which edge or corner is being dragged

	Start a pointer-driven resizing of the surface.

	This request must be used in response to a button press event.
	The server may ignore resize requests depending on the state of
	the surface (e.g. fullscreen or maximized).
      
  */
  void resize(seat_t seat, uint32_t serial, shell_surface_resize edges);

  /** \brief Minimum protocol version required for the \ref resize function
  */
  static constexpr std::uint32_t resize_since_version = 1;

  /** \brief make the surface a toplevel surface

	Map the surface as a toplevel surface.

	A toplevel surface is not fullscreen, maximized or transient.
      
  */
  void set_toplevel();

  /** \brief Minimum protocol version required for the \ref set_toplevel function
  */
  static constexpr std::uint32_t set_toplevel_since_version = 1;

  /** \brief make the surface a transient surface
      \param parent parent surface
      \param x surface-local x coordinate
      \param y surface-local y coordinate
      \param flags transient surface behavior

	Map the surface relative to an existing surface.

	The x and y arguments specify the location of the upper left
	corner of the surface relative to the upper left corner of the
	parent surface, in surface-local coordinates.

	The flags argument controls details of the transient behaviour.
      
  */
  void set_transient(surface_t parent, int32_t x, int32_t y, shell_surface_transient flags);

  /** \brief Minimum protocol version required for the \ref set_transient function
  */
  static constexpr std::uint32_t set_transient_since_version = 1;

  /** \brief make the surface a fullscreen surface
      \param method method for resolving size conflict
      \param framerate framerate in mHz
      \param output output on which the surface is to be fullscreen

	Map the surface as a fullscreen surface.

	If an output parameter is given then the surface will be made
	fullscreen on that output. If the client does not specify the
	output then the compositor will apply its policy - usually
	choosing the output on which the surface has the biggest surface
	area.

	The client may specify a method to resolve a size conflict
	between the output size and the surface size - this is provided
	through the method parameter.

	The framerate parameter is used only when the method is set
	to "driver", to indicate the preferred framerate. A value of 0
	indicates that the client does not care about framerate.  The
	framerate is specified in mHz, that is framerate of 60000 is 60Hz.

	A method of "scale" or "driver" implies a scaling operation of
	the surface, either via a direct scaling operation or a change of
	the output mode. This will override any kind of output scaling, so
	that mapping a surface with a buffer size equal to the mode can
	fill the screen independent of buffer_scale.

	A method of "fill" means we don't scale up the buffer, however
	any output scale is applied. This means that you may run into
	an edge case where the application maps a buffer with the same
	size of the output mode but buffer_scale 1 (thus making a
	surface larger than the output). In this case it is allowed to
	downscale the results to fit the screen.

	The compositor must reply to this request with a configure event
	with the dimensions for the output on which the surface will
	be made fullscreen.
      
  */
  void set_fullscreen(shell_surface_fullscreen_method method, uint32_t framerate, output_t output);

  /** \brief Minimum protocol version required for the \ref set_fullscreen function
  */
  static constexpr std::uint32_t set_fullscreen_since_version = 1;

  /** \brief make the surface a popup surface
      \param seat seat whose pointer is used
      \param serial serial number of the implicit grab on the pointer
      \param parent parent surface
      \param x surface-local x coordinate
      \param y surface-local y coordinate
      \param flags transient surface behavior

	Map the surface as a popup.

	A popup surface is a transient surface with an added pointer
	grab.

	An existing implicit grab will be changed to owner-events mode,
	and the popup grab will continue after the implicit grab ends
	(i.e. releasing the mouse button does not cause the popup to
	be unmapped).

	The popup grab continues until the window is destroyed or a
	mouse button is pressed in any other client's window. A click
	in any of the client's surfaces is reported as normal, however,
	clicks in other clients' surfaces will be discarded and trigger
	the callback.

	The x and y arguments specify the location of the upper left
	corner of the surface relative to the upper left corner of the
	parent surface, in surface-local coordinates.
      
  */
  void set_popup(seat_t seat, uint32_t serial, surface_t parent, int32_t x, int32_t y, shell_surface_transient flags);

  /** \brief Minimum protocol version required for the \ref set_popup function
  */
  static constexpr std::uint32_t set_popup_since_version = 1;

  /** \brief make the surface a maximized surface
      \param output output on which the surface is to be maximized

	Map the surface as a maximized surface.

	If an output parameter is given then the surface will be
	maximized on that output. If the client does not specify the
	output then the compositor will apply its policy - usually
	choosing the output on which the surface has the biggest surface
	area.

	The compositor will reply with a configure event telling
	the expected new surface size. The operation is completed
	on the next buffer attach to this surface.

	A maximized surface typically fills the entire output it is
	bound to, except for desktop elements such as panels. This is
	the main difference between a maximized shell surface and a
	fullscreen shell surface.

	The details depend on the compositor implementation.
      
  */
  void set_maximized(output_t output);

  /** \brief Minimum protocol version required for the \ref set_maximized function
  */
  static constexpr std::uint32_t set_maximized_since_version = 1;

  /** \brief set surface title
      \param title surface title

	Set a short title for the surface.

	This string may be used to identify the surface in a task bar,
	window list, or other user interface elements provided by the
	compositor.

	The string must be encoded in UTF-8.
      
  */
  void set_title(std::string title);

  /** \brief Minimum protocol version required for the \ref set_title function
  */
  static constexpr std::uint32_t set_title_since_version = 1;

  /** \brief set surface class
      \param class_ surface class

	Set a class for the surface.

	The surface class identifies the general class of applications
	to which the surface belongs. A common convention is to use the
	file name (or the full path if it is a non-standard location) of
	the application's .desktop file as the class.
      
  */
  void set_class(std::string class_);

  /** \brief Minimum protocol version required for the \ref set_class function
  */
  static constexpr std::uint32_t set_class_since_version = 1;

  /** \brief ping client
      \param serial serial number of the ping

	Ping a client to check if it is receiving events and sending
	requests. A client is expected to reply with a pong request.
      
  */
  std::function<void(uint32_t)> &on_ping();

  /** \brief suggest resize
      \param edges how the surface was resized
      \param width new width of the surface
      \param height new height of the surface

	The configure event asks the client to resize its surface.

	The size is a hint, in the sense that the client is free to
	ignore it if it doesn't resize, pick a smaller size (to
	satisfy aspect ratio or resize in steps of NxM pixels).

	The edges parameter provides a hint about how the surface
	was resized. The client may use this information to decide
	how to adjust its content to the new size (e.g. a scrolling
	area might adjust its content position to leave the viewable
	content unmoved).

	The client is free to dismiss all but the last configure
	event it received.

	The width and height arguments specify the size of the window
	in surface-local coordinates.
      
  */
  std::function<void(shell_surface_resize, int32_t, int32_t)> &on_configure();

  /** \brief popup interaction is done

	The popup_done event is sent out when a popup grab is broken,
	that is, when the user clicks a surface that doesn't belong
	to the client owning the popup surface.
      
  */
  std::function<void()> &on_popup_done();

};

/** \brief edge values for resizing

	These values are used to indicate which edge of a surface
	is being dragged in a resize operation. The server may
	use this information to adapt its behavior, e.g. choose
	an appropriate cursor image.
      
  */
struct shell_surface_resize : public detail::bitfield<4, 8>
{
  shell_surface_resize(const detail::bitfield<4, 8> &b)
    : detail::bitfield<4, 8>(b) {}
  shell_surface_resize(const uint32_t value)
    : detail::bitfield<4, 8>(value) {}
  /** \brief no edge */
  static const detail::bitfield<4, 8> none;
  /** \brief top edge */
  static const detail::bitfield<4, 8> top;
  /** \brief bottom edge */
  static const detail::bitfield<4, 8> bottom;
  /** \brief left edge */
  static const detail::bitfield<4, 8> left;
  /** \brief top and left edges */
  static const detail::bitfield<4, 8> top_left;
  /** \brief bottom and left edges */
  static const detail::bitfield<4, 8> bottom_left;
  /** \brief right edge */
  static const detail::bitfield<4, 8> right;
  /** \brief top and right edges */
  static const detail::bitfield<4, 8> top_right;
  /** \brief bottom and right edges */
  static const detail::bitfield<4, 8> bottom_right;
};

/** \brief details of transient behaviour

	These flags specify details of the expected behaviour
	of transient surfaces. Used in the set_transient request.
      
  */
struct shell_surface_transient : public detail::bitfield<1, 9>
{
  shell_surface_transient(const detail::bitfield<1, 9> &b)
    : detail::bitfield<1, 9>(b) {}
  shell_surface_transient(const uint32_t value)
    : detail::bitfield<1, 9>(value) {}
  /** \brief do not set keyboard focus */
  static const detail::bitfield<1, 9> inactive;
};

/** \brief different method to set the surface fullscreen

	Hints to indicate to the compositor how to deal with a conflict
	between the dimensions of the surface and the dimensions of the
	output. The compositor is free to ignore this parameter.
      
  */
enum class shell_surface_fullscreen_method : uint32_t
  {
  /** \brief no preference, apply default policy */
  _default = 0,
  /** \brief scale, preserve the surface's aspect ratio and center on output */
  scale = 1,
  /** \brief switch output mode to the smallest mode that can fit the surface, add black borders to compensate size mismatch */
  driver = 2,
  /** \brief no upscaling, center on output and add black borders to compensate size mismatch */
  fill = 3
};


/** \brief an onscreen surface

      A surface is a rectangular area that is displayed on the screen.
      It has a location, size and pixel contents.

      The size of a surface (and relative positions on it) is described
      in surface-local coordinates, which may differ from the buffer
      coordinates of the pixel content, in case a buffer_transform
      or a buffer_scale is used.

      A surface without a "role" is fairly useless: a compositor does
      not know where, when or how to present it. The role is the
      purpose of a wl_surface. Examples of roles are a cursor for a
      pointer (as set by wl_pointer.set_cursor), a drag icon
      (wl_data_device.start_drag), a sub-surface
      (wl_subcompositor.get_subsurface), and a window as defined by a
      shell protocol (e.g. wl_shell.get_shell_surface).

      A surface can have only one role at a time. Initially a
      wl_surface does not have a role. Once a wl_surface is given a
      role, it is set permanently for the whole lifetime of the
      wl_surface object. Giving the current role again is allowed,
      unless explicitly forbidden by the relevant interface
      specification.

      Surface roles are given by requests in other interfaces such as
      wl_pointer.set_cursor. The request should explicitly mention
      that this request gives a role to a wl_surface. Often, this
      request also creates a new protocol object that represents the
      role and adds additional functionality to wl_surface. When a
      client wants to destroy a wl_surface, they must destroy this 'role
      object' before the wl_surface.

      Destroying the role object does not remove the role from the
      wl_surface, but it may stop the wl_surface from "playing the role".
      For instance, if a wl_subsurface object is destroyed, the wl_surface
      it was created for will be unmapped and forget its position and
      z-order. It is allowed to create a wl_subsurface for the same
      wl_surface again, but it is not allowed to use the wl_surface as
      a cursor (cursor is a different role than sub-surface, and role
      switching is not allowed).
    
*/
class surface_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(output_t)> enter;
    std::function<void(output_t)> leave;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  surface_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  surface_t();
  explicit surface_t(const proxy_t &proxy);
  surface_t(wl_surface *p, wrapper_type t = wrapper_type::standard);

  surface_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_surface*() const;

  /** \brief set the surface contents
      \param buffer buffer of surface contents
      \param x surface-local x coordinate
      \param y surface-local y coordinate

	Set a buffer as the content of this surface.

	The new size of the surface is calculated based on the buffer
	size transformed by the inverse buffer_transform and the
	inverse buffer_scale. This means that the supplied buffer
	must be an integer multiple of the buffer_scale.

	The x and y arguments specify the location of the new pending
	buffer's upper left corner, relative to the current buffer's upper
	left corner, in surface-local coordinates. In other words, the
	x and y, combined with the new surface size define in which
	directions the surface's size changes.

	Surface contents are double-buffered state, see wl_surface.commit.

	The initial surface contents are void; there is no content.
	wl_surface.attach assigns the given wl_buffer as the pending
	wl_buffer. wl_surface.commit makes the pending wl_buffer the new
	surface contents, and the size of the surface becomes the size
	calculated from the wl_buffer, as described above. After commit,
	there is no pending buffer until the next attach.

	Committing a pending wl_buffer allows the compositor to read the
	pixels in the wl_buffer. The compositor may access the pixels at
	any time after the wl_surface.commit request. When the compositor
	will not access the pixels anymore, it will send the
	wl_buffer.release event. Only after receiving wl_buffer.release,
	the client may reuse the wl_buffer. A wl_buffer that has been
	attached and then replaced by another attach instead of committed
	will not receive a release event, and is not used by the
	compositor.

	Destroying the wl_buffer after wl_buffer.release does not change
	the surface contents. However, if the client destroys the
	wl_buffer before receiving the wl_buffer.release event, the surface
	contents become undefined immediately.

	If wl_surface.attach is sent with a NULL wl_buffer, the
	following wl_surface.commit will remove the surface content.
      
  */
  void attach(buffer_t buffer, int32_t x, int32_t y);

  /** \brief Minimum protocol version required for the \ref attach function
  */
  static constexpr std::uint32_t attach_since_version = 1;

  /** \brief mark part of the surface damaged
      \param x surface-local x coordinate
      \param y surface-local y coordinate
      \param width width of damage rectangle
      \param height height of damage rectangle

	This request is used to describe the regions where the pending
	buffer is different from the current surface contents, and where
	the surface therefore needs to be repainted. The compositor
	ignores the parts of the damage that fall outside of the surface.

	Damage is double-buffered state, see wl_surface.commit.

	The damage rectangle is specified in surface-local coordinates,
	where x and y specify the upper left corner of the damage rectangle.

	The initial value for pending damage is empty: no damage.
	wl_surface.damage adds pending damage: the new pending damage
	is the union of old pending damage and the given rectangle.

	wl_surface.commit assigns pending damage as the current damage,
	and clears pending damage. The server will clear the current
	damage as it repaints the surface.

	Note! New clients should not use this request. Instead damage can be
	posted with wl_surface.damage_buffer which uses buffer coordinates
	instead of surface coordinates.
      
  */
  void damage(int32_t x, int32_t y, int32_t width, int32_t height);

  /** \brief Minimum protocol version required for the \ref damage function
  */
  static constexpr std::uint32_t damage_since_version = 1;

  /** \brief request a frame throttling hint
      \return callback object for the frame request

	Request a notification when it is a good time to start drawing a new
	frame, by creating a frame callback. This is useful for throttling
	redrawing operations, and driving animations.

	When a client is animating on a wl_surface, it can use the 'frame'
	request to get notified when it is a good time to draw and commit the
	next frame of animation. If the client commits an update earlier than
	that, it is likely that some updates will not make it to the display,
	and the client is wasting resources by drawing too often.

	The frame request will take effect on the next wl_surface.commit.
	The notification will only be posted for one frame unless
	requested again. For a wl_surface, the notifications are posted in
	the order the frame requests were committed.

	The server must send the notifications so that a client
	will not send excessive updates, while still allowing
	the highest possible update rate for clients that wait for the reply
	before drawing again. The server should give some time for the client
	to draw and commit after sending the frame callback events to let it
	hit the next output refresh.

	A server should avoid signaling the frame callbacks if the
	surface is not visible in any way, e.g. the surface is off-screen,
	or completely obscured by other opaque surfaces.

	The object returned by this request will be destroyed by the
	compositor after the callback is fired and as such the client must not
	attempt to use it after that point.

	The callback_data passed in the callback is the current time, in
	milliseconds, with an undefined base.
      
  */
  callback_t frame();

  /** \brief Minimum protocol version required for the \ref frame function
  */
  static constexpr std::uint32_t frame_since_version = 1;

  /** \brief set opaque region
      \param region opaque region of the surface

	This request sets the region of the surface that contains
	opaque content.

	The opaque region is an optimization hint for the compositor
	that lets it optimize the redrawing of content behind opaque
	regions.  Setting an opaque region is not required for correct
	behaviour, but marking transparent content as opaque will result
	in repaint artifacts.

	The opaque region is specified in surface-local coordinates.

	The compositor ignores the parts of the opaque region that fall
	outside of the surface.

	Opaque region is double-buffered state, see wl_surface.commit.

	wl_surface.set_opaque_region changes the pending opaque region.
	wl_surface.commit copies the pending region to the current region.
	Otherwise, the pending and current regions are never changed.

	The initial value for an opaque region is empty. Setting the pending
	opaque region has copy semantics, and the wl_region object can be
	destroyed immediately. A NULL wl_region causes the pending opaque
	region to be set to empty.
      
  */
  void set_opaque_region(region_t region);

  /** \brief Minimum protocol version required for the \ref set_opaque_region function
  */
  static constexpr std::uint32_t set_opaque_region_since_version = 1;

  /** \brief set input region
      \param region input region of the surface

	This request sets the region of the surface that can receive
	pointer and touch events.

	Input events happening outside of this region will try the next
	surface in the server surface stack. The compositor ignores the
	parts of the input region that fall outside of the surface.

	The input region is specified in surface-local coordinates.

	Input region is double-buffered state, see wl_surface.commit.

	wl_surface.set_input_region changes the pending input region.
	wl_surface.commit copies the pending region to the current region.
	Otherwise the pending and current regions are never changed,
	except cursor and icon surfaces are special cases, see
	wl_pointer.set_cursor and wl_data_device.start_drag.

	The initial value for an input region is infinite. That means the
	whole surface will accept input. Setting the pending input region
	has copy semantics, and the wl_region object can be destroyed
	immediately. A NULL wl_region causes the input region to be set
	to infinite.
      
  */
  void set_input_region(region_t region);

  /** \brief Minimum protocol version required for the \ref set_input_region function
  */
  static constexpr std::uint32_t set_input_region_since_version = 1;

  /** \brief commit pending surface state

	Surface state (input, opaque, and damage regions, attached buffers,
	etc.) is double-buffered. Protocol requests modify the pending state,
	as opposed to the current state in use by the compositor. A commit
	request atomically applies all pending state, replacing the current
	state. After commit, the new pending state is as documented for each
	related request.

	On commit, a pending wl_buffer is applied first, and all other state
	second. This means that all coordinates in double-buffered state are
	relative to the new wl_buffer coming into use, except for
	wl_surface.attach itself. If there is no pending wl_buffer, the
	coordinates are relative to the current surface contents.

	All requests that need a commit to become effective are documented
	to affect double-buffered state.

	Other interfaces may add further double-buffered surface state.
      
  */
  void commit();

  /** \brief Minimum protocol version required for the \ref commit function
  */
  static constexpr std::uint32_t commit_since_version = 1;

  /** \brief sets the buffer transformation
      \param transform transform for interpreting buffer contents

	This request sets an optional transformation on how the compositor
	interprets the contents of the buffer attached to the surface. The
	accepted values for the transform parameter are the values for
	wl_output.transform.

	Buffer transform is double-buffered state, see wl_surface.commit.

	A newly created surface has its buffer transformation set to normal.

	wl_surface.set_buffer_transform changes the pending buffer
	transformation. wl_surface.commit copies the pending buffer
	transformation to the current one. Otherwise, the pending and current
	values are never changed.

	The purpose of this request is to allow clients to render content
	according to the output transform, thus permitting the compositor to
	use certain optimizations even if the display is rotated. Using
	hardware overlays and scanning out a client buffer for fullscreen
	surfaces are examples of such optimizations. Those optimizations are
	highly dependent on the compositor implementation, so the use of this
	request should be considered on a case-by-case basis.

	Note that if the transform value includes 90 or 270 degree rotation,
	the width of the buffer will become the surface height and the height
	of the buffer will become the surface width.

	If transform is not one of the values from the
	wl_output.transform enum the invalid_transform protocol error
	is raised.
      
  */
  void set_buffer_transform(output_transform transform);

  /** \brief Minimum protocol version required for the \ref set_buffer_transform function
  */
  static constexpr std::uint32_t set_buffer_transform_since_version = 2;

  /** \brief Check whether the \ref set_buffer_transform function is available with
      the currently bound version of the protocol
  */
  bool can_set_buffer_transform() const;

  /** \brief sets the buffer scaling factor
      \param scale positive scale for interpreting buffer contents

	This request sets an optional scaling factor on how the compositor
	interprets the contents of the buffer attached to the window.

	Buffer scale is double-buffered state, see wl_surface.commit.

	A newly created surface has its buffer scale set to 1.

	wl_surface.set_buffer_scale changes the pending buffer scale.
	wl_surface.commit copies the pending buffer scale to the current one.
	Otherwise, the pending and current values are never changed.

	The purpose of this request is to allow clients to supply higher
	resolution buffer data for use on high resolution outputs. It is
	intended that you pick the same buffer scale as the scale of the
	output that the surface is displayed on. This means the compositor
	can avoid scaling when rendering the surface on that output.

	Note that if the scale is larger than 1, then you have to attach
	a buffer that is larger (by a factor of scale in each dimension)
	than the desired surface size.

	If scale is not positive the invalid_scale protocol error is
	raised.
      
  */
  void set_buffer_scale(int32_t scale);

  /** \brief Minimum protocol version required for the \ref set_buffer_scale function
  */
  static constexpr std::uint32_t set_buffer_scale_since_version = 3;

  /** \brief Check whether the \ref set_buffer_scale function is available with
      the currently bound version of the protocol
  */
  bool can_set_buffer_scale() const;

  /** \brief mark part of the surface damaged using buffer coordinates
      \param x buffer-local x coordinate
      \param y buffer-local y coordinate
      \param width width of damage rectangle
      \param height height of damage rectangle

	This request is used to describe the regions where the pending
	buffer is different from the current surface contents, and where
	the surface therefore needs to be repainted. The compositor
	ignores the parts of the damage that fall outside of the surface.

	Damage is double-buffered state, see wl_surface.commit.

	The damage rectangle is specified in buffer coordinates,
	where x and y specify the upper left corner of the damage rectangle.

	The initial value for pending damage is empty: no damage.
	wl_surface.damage_buffer adds pending damage: the new pending
	damage is the union of old pending damage and the given rectangle.

	wl_surface.commit assigns pending damage as the current damage,
	and clears pending damage. The server will clear the current
	damage as it repaints the surface.

	This request differs from wl_surface.damage in only one way - it
	takes damage in buffer coordinates instead of surface-local
	coordinates. While this generally is more intuitive than surface
	coordinates, it is especially desirable when using wp_viewport
	or when a drawing library (like EGL) is unaware of buffer scale
	and buffer transform.

	Note: Because buffer transformation changes and damage requests may
	be interleaved in the protocol stream, it is impossible to determine
	the actual mapping between surface and buffer damage until
	wl_surface.commit time. Therefore, compositors wishing to take both
	kinds of damage into account will have to accumulate damage from the
	two requests separately and only transform from one to the other
	after receiving the wl_surface.commit.
      
  */
  void damage_buffer(int32_t x, int32_t y, int32_t width, int32_t height);

  /** \brief Minimum protocol version required for the \ref damage_buffer function
  */
  static constexpr std::uint32_t damage_buffer_since_version = 4;

  /** \brief Check whether the \ref damage_buffer function is available with
      the currently bound version of the protocol
  */
  bool can_damage_buffer() const;

  /** \brief surface enters an output
      \param output output entered by the surface

	This is emitted whenever a surface's creation, movement, or resizing
	results in some part of it being within the scanout region of an
	output.

	Note that a surface may be overlapping with zero or more outputs.
      
  */
  std::function<void(output_t)> &on_enter();

  /** \brief surface leaves an output
      \param output output left by the surface

	This is emitted whenever a surface's creation, movement, or resizing
	results in it no longer having any part of it within the scanout region
	of an output.
      
  */
  std::function<void(output_t)> &on_leave();

};

/** \brief wl_surface error values

	These errors can be emitted in response to wl_surface requests.
      
  */
enum class surface_error : uint32_t
  {
  /** \brief buffer scale value is invalid */
  invalid_scale = 0,
  /** \brief buffer transform value is invalid */
  invalid_transform = 1
};


/** \brief group of input devices

      A seat is a group of keyboards, pointer and touch devices. This
      object is published as a global during start up, or when such a
      device is hot plugged.  A seat typically has a pointer and
      maintains a keyboard focus and a pointer focus.
    
*/
class seat_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(seat_capability)> capabilities;
    std::function<void(std::string)> name;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  seat_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  seat_t();
  explicit seat_t(const proxy_t &proxy);
  seat_t(wl_seat *p, wrapper_type t = wrapper_type::standard);

  seat_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_seat*() const;

  /** \brief return pointer object
      \return seat pointer

	The ID provided will be initialized to the wl_pointer interface
	for this seat.

	This request only takes effect if the seat has the pointer
	capability, or has had the pointer capability in the past.
	It is a protocol violation to issue this request on a seat that has
	never had the pointer capability.
      
  */
  pointer_t get_pointer();

  /** \brief Minimum protocol version required for the \ref get_pointer function
  */
  static constexpr std::uint32_t get_pointer_since_version = 1;

  /** \brief return keyboard object
      \return seat keyboard

	The ID provided will be initialized to the wl_keyboard interface
	for this seat.

	This request only takes effect if the seat has the keyboard
	capability, or has had the keyboard capability in the past.
	It is a protocol violation to issue this request on a seat that has
	never had the keyboard capability.
      
  */
  keyboard_t get_keyboard();

  /** \brief Minimum protocol version required for the \ref get_keyboard function
  */
  static constexpr std::uint32_t get_keyboard_since_version = 1;

  /** \brief return touch object
      \return seat touch interface

	The ID provided will be initialized to the wl_touch interface
	for this seat.

	This request only takes effect if the seat has the touch
	capability, or has had the touch capability in the past.
	It is a protocol violation to issue this request on a seat that has
	never had the touch capability.
      
  */
  touch_t get_touch();

  /** \brief Minimum protocol version required for the \ref get_touch function
  */
  static constexpr std::uint32_t get_touch_since_version = 1;

  /** \brief release the seat object

	Using this request a client can tell the server that it is not going to
	use the seat object anymore.
      
  */
  void release();

  /** \brief Minimum protocol version required for the \ref release function
  */
  static constexpr std::uint32_t release_since_version = 5;

  /** \brief Check whether the \ref release function is available with
      the currently bound version of the protocol
  */
  bool can_release() const;

  /** \brief seat capabilities changed
      \param capabilities capabilities of the seat

	This is emitted whenever a seat gains or loses the pointer,
	keyboard or touch capabilities.  The argument is a capability
	enum containing the complete set of capabilities this seat has.

	When the pointer capability is added, a client may create a
	wl_pointer object using the wl_seat.get_pointer request. This object
	will receive pointer events until the capability is removed in the
	future.

	When the pointer capability is removed, a client should destroy the
	wl_pointer objects associated with the seat where the capability was
	removed, using the wl_pointer.release request. No further pointer
	events will be received on these objects.

	In some compositors, if a seat regains the pointer capability and a
	client has a previously obtained wl_pointer object of version 4 or
	less, that object may start sending pointer events again. This
	behavior is considered a misinterpretation of the intended behavior
	and must not be relied upon by the client. wl_pointer objects of
	version 5 or later must not send events if created before the most
	recent event notifying the client of an added pointer capability.

	The above behavior also applies to wl_keyboard and wl_touch with the
	keyboard and touch capabilities, respectively.
      
  */
  std::function<void(seat_capability)> &on_capabilities();

  /** \brief unique identifier for this seat
      \param name seat identifier

	In a multiseat configuration this can be used by the client to help
	identify which physical devices the seat represents. Based on
	the seat configuration used by the compositor.
      
  */
  std::function<void(std::string)> &on_name();

};

/** \brief seat capability bitmask

	This is a bitmask of capabilities this seat has; if a member is
	set, then it is present on the seat.
      
  */
struct seat_capability : public detail::bitfield<3, 12>
{
  seat_capability(const detail::bitfield<3, 12> &b)
    : detail::bitfield<3, 12>(b) {}
  seat_capability(const uint32_t value)
    : detail::bitfield<3, 12>(value) {}
  /** \brief the seat has pointer devices */
  static const detail::bitfield<3, 12> pointer;
  /** \brief the seat has one or more keyboards */
  static const detail::bitfield<3, 12> keyboard;
  /** \brief the seat has touch devices */
  static const detail::bitfield<3, 12> touch;
};


/** \brief pointer input device

      The wl_pointer interface represents one or more input devices,
      such as mice, which control the pointer location and pointer_focus
      of a seat.

      The wl_pointer interface generates motion, enter and leave
      events for the surfaces that the pointer is located over,
      and button and axis events for button presses, button releases
      and scrolling.
    
*/
class pointer_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(uint32_t, surface_t, double, double)> enter;
    std::function<void(uint32_t, surface_t)> leave;
    std::function<void(uint32_t, double, double)> motion;
    std::function<void(uint32_t, uint32_t, uint32_t, pointer_button_state)> button;
    std::function<void(uint32_t, pointer_axis, double)> axis;
    std::function<void()> frame;
    std::function<void(pointer_axis_source)> axis_source;
    std::function<void(uint32_t, pointer_axis)> axis_stop;
    std::function<void(pointer_axis, int32_t)> axis_discrete;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  pointer_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  pointer_t();
  explicit pointer_t(const proxy_t &proxy);
  pointer_t(wl_pointer *p, wrapper_type t = wrapper_type::standard);

  pointer_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_pointer*() const;

  /** \brief set the pointer surface
      \param serial serial number of the enter event
      \param surface pointer surface
      \param hotspot_x surface-local x coordinate
      \param hotspot_y surface-local y coordinate

	Set the pointer surface, i.e., the surface that contains the
	pointer image (cursor). This request gives the surface the role
	of a cursor. If the surface already has another role, it raises
	a protocol error.

	The cursor actually changes only if the pointer
	focus for this device is one of the requesting client's surfaces
	or the surface parameter is the current pointer surface. If
	there was a previous surface set with this request it is
	replaced. If surface is NULL, the pointer image is hidden.

	The parameters hotspot_x and hotspot_y define the position of
	the pointer surface relative to the pointer location. Its
	top-left corner is always at (x, y) - (hotspot_x, hotspot_y),
	where (x, y) are the coordinates of the pointer location, in
	surface-local coordinates.

	On surface.attach requests to the pointer surface, hotspot_x
	and hotspot_y are decremented by the x and y parameters
	passed to the request. Attach must be confirmed by
	wl_surface.commit as usual.

	The hotspot can also be updated by passing the currently set
	pointer surface to this request with new values for hotspot_x
	and hotspot_y.

	The current and pending input regions of the wl_surface are
	cleared, and wl_surface.set_input_region is ignored until the
	wl_surface is no longer used as the cursor. When the use as a
	cursor ends, the current and pending input regions become
	undefined, and the wl_surface is unmapped.
      
  */
  void set_cursor(uint32_t serial, surface_t surface, int32_t hotspot_x, int32_t hotspot_y);

  /** \brief Minimum protocol version required for the \ref set_cursor function
  */
  static constexpr std::uint32_t set_cursor_since_version = 1;

  /** \brief release the pointer object

	Using this request a client can tell the server that it is not going to
	use the pointer object anymore.

	This request destroys the pointer proxy object, so clients must not call
	wl_pointer_destroy() after using this request.
      
  */
  void release();

  /** \brief Minimum protocol version required for the \ref release function
  */
  static constexpr std::uint32_t release_since_version = 3;

  /** \brief Check whether the \ref release function is available with
      the currently bound version of the protocol
  */
  bool can_release() const;

  /** \brief enter event
      \param serial serial number of the enter event
      \param surface surface entered by the pointer
      \param surface_x surface-local x coordinate
      \param surface_y surface-local y coordinate

	Notification that this seat's pointer is focused on a certain
	surface.

	When a seat's focus enters a surface, the pointer image
	is undefined and a client should respond to this event by setting
	an appropriate pointer image with the set_cursor request.
      
  */
  std::function<void(uint32_t, surface_t, double, double)> &on_enter();

  /** \brief leave event
      \param serial serial number of the leave event
      \param surface surface left by the pointer

	Notification that this seat's pointer is no longer focused on
	a certain surface.

	The leave notification is sent before the enter notification
	for the new focus.
      
  */
  std::function<void(uint32_t, surface_t)> &on_leave();

  /** \brief pointer motion event
      \param time timestamp with millisecond granularity
      \param surface_x surface-local x coordinate
      \param surface_y surface-local y coordinate

	Notification of pointer location change. The arguments
	surface_x and surface_y are the location relative to the
	focused surface.
      
  */
  std::function<void(uint32_t, double, double)> &on_motion();

  /** \brief pointer button event
      \param serial serial number of the button event
      \param time timestamp with millisecond granularity
      \param button button that produced the event
      \param state physical state of the button

	Mouse button click and release notifications.

	The location of the click is given by the last motion or
	enter event.
	The time argument is a timestamp with millisecond
	granularity, with an undefined base.

	The button is a button code as defined in the Linux kernel's
	linux/input-event-codes.h header file, e.g. BTN_LEFT.

	Any 16-bit button code value is reserved for future additions to the
	kernel's event code list. All other button codes above 0xFFFF are
	currently undefined but may be used in future versions of this
	protocol.
      
  */
  std::function<void(uint32_t, uint32_t, uint32_t, pointer_button_state)> &on_button();

  /** \brief axis event
      \param time timestamp with millisecond granularity
      \param axis axis type
      \param value length of vector in surface-local coordinate space

	Scroll and other axis notifications.

	For scroll events (vertical and horizontal scroll axes), the
	value parameter is the length of a vector along the specified
	axis in a coordinate space identical to those of motion events,
	representing a relative movement along the specified axis.

	For devices that support movements non-parallel to axes multiple
	axis events will be emitted.

	When applicable, for example for touch pads, the server can
	choose to emit scroll events where the motion vector is
	equivalent to a motion event vector.

	When applicable, a client can transform its content relative to the
	scroll distance.
      
  */
  std::function<void(uint32_t, pointer_axis, double)> &on_axis();

  /** \brief end of a pointer event sequence

	Indicates the end of a set of events that logically belong together.
	A client is expected to accumulate the data in all events within the
	frame before proceeding.

	All wl_pointer events before a wl_pointer.frame event belong
	logically together. For example, in a diagonal scroll motion the
	compositor will send an optional wl_pointer.axis_source event, two
	wl_pointer.axis events (horizontal and vertical) and finally a
	wl_pointer.frame event. The client may use this information to
	calculate a diagonal vector for scrolling.

	When multiple wl_pointer.axis events occur within the same frame,
	the motion vector is the combined motion of all events.
	When a wl_pointer.axis and a wl_pointer.axis_stop event occur within
	the same frame, this indicates that axis movement in one axis has
	stopped but continues in the other axis.
	When multiple wl_pointer.axis_stop events occur within the same
	frame, this indicates that these axes stopped in the same instance.

	A wl_pointer.frame event is sent for every logical event group,
	even if the group only contains a single wl_pointer event.
	Specifically, a client may get a sequence: motion, frame, button,
	frame, axis, frame, axis_stop, frame.

	The wl_pointer.enter and wl_pointer.leave events are logical events
	generated by the compositor and not the hardware. These events are
	also grouped by a wl_pointer.frame. When a pointer moves from one
	surface to another, a compositor should group the
	wl_pointer.leave event within the same wl_pointer.frame.
	However, a client must not rely on wl_pointer.leave and
	wl_pointer.enter being in the same wl_pointer.frame.
	Compositor-specific policies may require the wl_pointer.leave and
	wl_pointer.enter event being split across multiple wl_pointer.frame
	groups.
      
  */
  std::function<void()> &on_frame();

  /** \brief axis source event
      \param axis_source source of the axis event

	Source information for scroll and other axes.

	This event does not occur on its own. It is sent before a
	wl_pointer.frame event and carries the source information for
	all events within that frame.

	The source specifies how this event was generated. If the source is
	wl_pointer.axis_source.finger, a wl_pointer.axis_stop event will be
	sent when the user lifts the finger off the device.

	If the source is wl_pointer.axis_source.wheel,
	wl_pointer.axis_source.wheel_tilt or
	wl_pointer.axis_source.continuous, a wl_pointer.axis_stop event may
	or may not be sent. Whether a compositor sends an axis_stop event
	for these sources is hardware-specific and implementation-dependent;
	clients must not rely on receiving an axis_stop event for these
	scroll sources and should treat scroll sequences from these scroll
	sources as unterminated by default.

	This event is optional. If the source is unknown for a particular
	axis event sequence, no event is sent.
	Only one wl_pointer.axis_source event is permitted per frame.

	The order of wl_pointer.axis_discrete and wl_pointer.axis_source is
	not guaranteed.
      
  */
  std::function<void(pointer_axis_source)> &on_axis_source();

  /** \brief axis stop event
      \param time timestamp with millisecond granularity
      \param axis the axis stopped with this event

	Stop notification for scroll and other axes.

	For some wl_pointer.axis_source types, a wl_pointer.axis_stop event
	is sent to notify a client that the axis sequence has terminated.
	This enables the client to implement kinetic scrolling.
	See the wl_pointer.axis_source documentation for information on when
	this event may be generated.

	Any wl_pointer.axis events with the same axis_source after this
	event should be considered as the start of a new axis motion.

	The timestamp is to be interpreted identical to the timestamp in the
	wl_pointer.axis event. The timestamp value may be the same as a
	preceding wl_pointer.axis event.
      
  */
  std::function<void(uint32_t, pointer_axis)> &on_axis_stop();

  /** \brief axis click event
      \param axis axis type
      \param discrete number of steps

	Discrete step information for scroll and other axes.

	This event carries the axis value of the wl_pointer.axis event in
	discrete steps (e.g. mouse wheel clicks).

	This event does not occur on its own, it is coupled with a
	wl_pointer.axis event that represents this axis value on a
	continuous scale. The protocol guarantees that each axis_discrete
	event is always followed by exactly one axis event with the same
	axis number within the same wl_pointer.frame. Note that the protocol
	allows for other events to occur between the axis_discrete and
	its coupled axis event, including other axis_discrete or axis
	events.

	This event is optional; continuous scrolling devices
	like two-finger scrolling on touchpads do not have discrete
	steps and do not generate this event.

	The discrete value carries the directional information. e.g. a value
	of -2 is two steps towards the negative direction of this axis.

	The axis number is identical to the axis number in the associated
	axis event.

	The order of wl_pointer.axis_discrete and wl_pointer.axis_source is
	not guaranteed.
      
  */
  std::function<void(pointer_axis, int32_t)> &on_axis_discrete();

};

/** \brief 

  */
enum class pointer_error : uint32_t
  {
  /** \brief given wl_surface has another role */
  role = 0
};

/** \brief physical button state

	Describes the physical state of a button that produced the button
	event.
      
  */
enum class pointer_button_state : uint32_t
  {
  /** \brief the button is not pressed */
  released = 0,
  /** \brief the button is pressed */
  pressed = 1
};

/** \brief axis types

	Describes the axis types of scroll events.
      
  */
enum class pointer_axis : uint32_t
  {
  /** \brief vertical axis */
  vertical_scroll = 0,
  /** \brief horizontal axis */
  horizontal_scroll = 1
};

/** \brief axis source types

	Describes the source types for axis events. This indicates to the
	client how an axis event was physically generated; a client may
	adjust the user interface accordingly. For example, scroll events
	from a "finger" source may be in a smooth coordinate space with
	kinetic scrolling whereas a "wheel" source may be in discrete steps
	of a number of lines.

	The "continuous" axis source is a device generating events in a
	continuous coordinate space, but using something other than a
	finger. One example for this source is button-based scrolling where
	the vertical motion of a device is converted to scroll events while
	a button is held down.

	The "wheel tilt" axis source indicates that the actual device is a
	wheel but the scroll event is not caused by a rotation but a
	(usually sideways) tilt of the wheel.
      
  */
enum class pointer_axis_source : uint32_t
  {
  /** \brief a physical wheel rotation */
  wheel = 0,
  /** \brief finger on a touch surface */
  finger = 1,
  /** \brief continuous coordinate space */
  continuous = 2,
  /** \brief a physical wheel tilt */
  wheel_tilt = 3
};


/** \brief keyboard input device

      The wl_keyboard interface represents one or more keyboards
      associated with a seat.
    
*/
class keyboard_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(keyboard_keymap_format, int, uint32_t)> keymap;
    std::function<void(uint32_t, surface_t, array_t)> enter;
    std::function<void(uint32_t, surface_t)> leave;
    std::function<void(uint32_t, uint32_t, uint32_t, keyboard_key_state)> key;
    std::function<void(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)> modifiers;
    std::function<void(int32_t, int32_t)> repeat_info;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  keyboard_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  keyboard_t();
  explicit keyboard_t(const proxy_t &proxy);
  keyboard_t(wl_keyboard *p, wrapper_type t = wrapper_type::standard);

  keyboard_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_keyboard*() const;

  /** \brief release the keyboard object

  */
  void release();

  /** \brief Minimum protocol version required for the \ref release function
  */
  static constexpr std::uint32_t release_since_version = 3;

  /** \brief Check whether the \ref release function is available with
      the currently bound version of the protocol
  */
  bool can_release() const;

  /** \brief keyboard mapping
      \param format keymap format
      \param fd keymap file descriptor
      \param size keymap size, in bytes

	This event provides a file descriptor to the client which can be
	memory-mapped to provide a keyboard mapping description.

	From version 7 onwards, the fd must be mapped with MAP_PRIVATE by
	the recipient, as MAP_SHARED may fail.
      
  */
  std::function<void(keyboard_keymap_format, int, uint32_t)> &on_keymap();

  /** \brief enter event
      \param serial serial number of the enter event
      \param surface surface gaining keyboard focus
      \param keys the currently pressed keys

	Notification that this seat's keyboard focus is on a certain
	surface.
      
  */
  std::function<void(uint32_t, surface_t, array_t)> &on_enter();

  /** \brief leave event
      \param serial serial number of the leave event
      \param surface surface that lost keyboard focus

	Notification that this seat's keyboard focus is no longer on
	a certain surface.

	The leave notification is sent before the enter notification
	for the new focus.
      
  */
  std::function<void(uint32_t, surface_t)> &on_leave();

  /** \brief key event
      \param serial serial number of the key event
      \param time timestamp with millisecond granularity
      \param key key that produced the event
      \param state physical state of the key

	A key was pressed or released.
	The time argument is a timestamp with millisecond
	granularity, with an undefined base.
      
  */
  std::function<void(uint32_t, uint32_t, uint32_t, keyboard_key_state)> &on_key();

  /** \brief modifier and group state
      \param serial serial number of the modifiers event
      \param mods_depressed depressed modifiers
      \param mods_latched latched modifiers
      \param mods_locked locked modifiers
      \param group keyboard layout

	Notifies clients that the modifier and/or group state has
	changed, and it should update its local state.
      
  */
  std::function<void(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)> &on_modifiers();

  /** \brief repeat rate and delay
      \param rate the rate of repeating keys in characters per second
      \param delay delay in milliseconds since key down until repeating starts

	Informs the client about the keyboard's repeat rate and delay.

	This event is sent as soon as the wl_keyboard object has been created,
	and is guaranteed to be received by the client before any key press
	event.

	Negative values for either rate or delay are illegal. A rate of zero
	will disable any repeating (regardless of the value of delay).

	This event can be sent later on as well with a new value if necessary,
	so clients should continue listening for the event past the creation
	of wl_keyboard.
      
  */
  std::function<void(int32_t, int32_t)> &on_repeat_info();

};

/** \brief keyboard mapping format

	This specifies the format of the keymap provided to the
	client with the wl_keyboard.keymap event.
      
  */
enum class keyboard_keymap_format : uint32_t
  {
  /** \brief no keymap; client must understand how to interpret the raw keycode */
  no_keymap = 0,
  /** \brief libxkbcommon compatible; to determine the xkb keycode, clients must add 8 to the key event keycode */
  xkb_v1 = 1
};

/** \brief physical key state

	Describes the physical state of a key that produced the key event.
      
  */
enum class keyboard_key_state : uint32_t
  {
  /** \brief key is not pressed */
  released = 0,
  /** \brief key is pressed */
  pressed = 1
};


/** \brief touchscreen input device

      The wl_touch interface represents a touchscreen
      associated with a seat.

      Touch interactions can consist of one or more contacts.
      For each contact, a series of events is generated, starting
      with a down event, followed by zero or more motion events,
      and ending with an up event. Events relating to the same
      contact point can be identified by the ID of the sequence.
    
*/
class touch_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(uint32_t, uint32_t, surface_t, int32_t, double, double)> down;
    std::function<void(uint32_t, uint32_t, int32_t)> up;
    std::function<void(uint32_t, int32_t, double, double)> motion;
    std::function<void()> frame;
    std::function<void()> cancel;
    std::function<void(int32_t, double, double)> shape;
    std::function<void(int32_t, double)> orientation;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  touch_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  touch_t();
  explicit touch_t(const proxy_t &proxy);
  touch_t(wl_touch *p, wrapper_type t = wrapper_type::standard);

  touch_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_touch*() const;

  /** \brief release the touch object

  */
  void release();

  /** \brief Minimum protocol version required for the \ref release function
  */
  static constexpr std::uint32_t release_since_version = 3;

  /** \brief Check whether the \ref release function is available with
      the currently bound version of the protocol
  */
  bool can_release() const;

  /** \brief touch down event and beginning of a touch sequence
      \param serial serial number of the touch down event
      \param time timestamp with millisecond granularity
      \param surface surface touched
      \param id the unique ID of this touch point
      \param x surface-local x coordinate
      \param y surface-local y coordinate

	A new touch point has appeared on the surface. This touch point is
	assigned a unique ID. Future events from this touch point reference
	this ID. The ID ceases to be valid after a touch up event and may be
	reused in the future.
      
  */
  std::function<void(uint32_t, uint32_t, surface_t, int32_t, double, double)> &on_down();

  /** \brief end of a touch event sequence
      \param serial serial number of the touch up event
      \param time timestamp with millisecond granularity
      \param id the unique ID of this touch point

	The touch point has disappeared. No further events will be sent for
	this touch point and the touch point's ID is released and may be
	reused in a future touch down event.
      
  */
  std::function<void(uint32_t, uint32_t, int32_t)> &on_up();

  /** \brief update of touch point coordinates
      \param time timestamp with millisecond granularity
      \param id the unique ID of this touch point
      \param x surface-local x coordinate
      \param y surface-local y coordinate

	A touch point has changed coordinates.
      
  */
  std::function<void(uint32_t, int32_t, double, double)> &on_motion();

  /** \brief end of touch frame event

	Indicates the end of a set of events that logically belong together.
	A client is expected to accumulate the data in all events within the
	frame before proceeding.

	A wl_touch.frame terminates at least one event but otherwise no
	guarantee is provided about the set of events within a frame. A client
	must assume that any state not updated in a frame is unchanged from the
	previously known state.
      
  */
  std::function<void()> &on_frame();

  /** \brief touch session cancelled

	Sent if the compositor decides the touch stream is a global
	gesture. No further events are sent to the clients from that
	particular gesture. Touch cancellation applies to all touch points
	currently active on this client's surface. The client is
	responsible for finalizing the touch points, future touch points on
	this surface may reuse the touch point ID.
      
  */
  std::function<void()> &on_cancel();

  /** \brief update shape of touch point
      \param id the unique ID of this touch point
      \param major length of the major axis in surface-local coordinates
      \param minor length of the minor axis in surface-local coordinates

	Sent when a touchpoint has changed its shape.

	This event does not occur on its own. It is sent before a
	wl_touch.frame event and carries the new shape information for
	any previously reported, or new touch points of that frame.

	Other events describing the touch point such as wl_touch.down,
	wl_touch.motion or wl_touch.orientation may be sent within the
	same wl_touch.frame. A client should treat these events as a single
	logical touch point update. The order of wl_touch.shape,
	wl_touch.orientation and wl_touch.motion is not guaranteed.
	A wl_touch.down event is guaranteed to occur before the first
	wl_touch.shape event for this touch ID but both events may occur within
	the same wl_touch.frame.

	A touchpoint shape is approximated by an ellipse through the major and
	minor axis length. The major axis length describes the longer diameter
	of the ellipse, while the minor axis length describes the shorter
	diameter. Major and minor are orthogonal and both are specified in
	surface-local coordinates. The center of the ellipse is always at the
	touchpoint location as reported by wl_touch.down or wl_touch.move.

	This event is only sent by the compositor if the touch device supports
	shape reports. The client has to make reasonable assumptions about the
	shape if it did not receive this event.
      
  */
  std::function<void(int32_t, double, double)> &on_shape();

  /** \brief update orientation of touch point
      \param id the unique ID of this touch point
      \param orientation angle between major axis and positive surface y-axis in degrees

	Sent when a touchpoint has changed its orientation.

	This event does not occur on its own. It is sent before a
	wl_touch.frame event and carries the new shape information for
	any previously reported, or new touch points of that frame.

	Other events describing the touch point such as wl_touch.down,
	wl_touch.motion or wl_touch.shape may be sent within the
	same wl_touch.frame. A client should treat these events as a single
	logical touch point update. The order of wl_touch.shape,
	wl_touch.orientation and wl_touch.motion is not guaranteed.
	A wl_touch.down event is guaranteed to occur before the first
	wl_touch.orientation event for this touch ID but both events may occur
	within the same wl_touch.frame.

	The orientation describes the clockwise angle of a touchpoint's major
	axis to the positive surface y-axis and is normalized to the -180 to
	+180 degree range. The granularity of orientation depends on the touch
	device, some devices only support binary rotation values between 0 and
	90 degrees.

	This event is only sent by the compositor if the touch device supports
	orientation reports.
      
  */
  std::function<void(int32_t, double)> &on_orientation();

};


/** \brief compositor output region

      An output describes part of the compositor geometry.  The
      compositor works in the 'compositor coordinate system' and an
      output corresponds to a rectangular area in that space that is
      actually visible.  This typically corresponds to a monitor that
      displays part of the compositor space.  This object is published
      as global during start up, or when a monitor is hotplugged.
    
*/
class output_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(int32_t, int32_t, int32_t, int32_t, output_subpixel, std::string, std::string, output_transform)> geometry;
    std::function<void(output_mode, int32_t, int32_t, int32_t)> mode;
    std::function<void()> done;
    std::function<void(int32_t)> scale;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  output_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  output_t();
  explicit output_t(const proxy_t &proxy);
  output_t(wl_output *p, wrapper_type t = wrapper_type::standard);

  output_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_output*() const;

  /** \brief release the output object

	Using this request a client can tell the server that it is not going to
	use the output object anymore.
      
  */
  void release();

  /** \brief Minimum protocol version required for the \ref release function
  */
  static constexpr std::uint32_t release_since_version = 3;

  /** \brief Check whether the \ref release function is available with
      the currently bound version of the protocol
  */
  bool can_release() const;

  /** \brief properties of the output
      \param x x position within the global compositor space
      \param y y position within the global compositor space
      \param physical_width width in millimeters of the output
      \param physical_height height in millimeters of the output
      \param subpixel subpixel orientation of the output
      \param make textual description of the manufacturer
      \param model textual description of the model
      \param transform transform that maps framebuffer to output

	The geometry event describes geometric properties of the output.
	The event is sent when binding to the output object and whenever
	any of the properties change.

	The physical size can be set to zero if it doesn't make sense for this
	output (e.g. for projectors or virtual outputs).

	Note: wl_output only advertises partial information about the output
	position and identification. Some compositors, for instance those not
	implementing a desktop-style output layout or those exposing virtual
	outputs, might fake this information. Instead of using x and y, clients
	should use xdg_output.logical_position. Instead of using make and model,
	clients should use xdg_output.name and xdg_output.description.
      
  */
  std::function<void(int32_t, int32_t, int32_t, int32_t, output_subpixel, std::string, std::string, output_transform)> &on_geometry();

  /** \brief advertise available modes for the output
      \param flags bitfield of mode flags
      \param width width of the mode in hardware units
      \param height height of the mode in hardware units
      \param refresh vertical refresh rate in mHz

	The mode event describes an available mode for the output.

	The event is sent when binding to the output object and there
	will always be one mode, the current mode.  The event is sent
	again if an output changes mode, for the mode that is now
	current.  In other words, the current mode is always the last
	mode that was received with the current flag set.

	The size of a mode is given in physical hardware units of
	the output device. This is not necessarily the same as
	the output size in the global compositor space. For instance,
	the output may be scaled, as described in wl_output.scale,
	or transformed, as described in wl_output.transform. Clients
	willing to retrieve the output size in the global compositor
	space should use xdg_output.logical_size instead.

	Clients should not use the refresh rate to schedule frames. Instead,
	they should use the wl_surface.frame event or the presentation-time
	protocol.

	Note: this information is not always meaningful for all outputs. Some
	compositors, such as those exposing virtual outputs, might fake the
	refresh rate or the size.
      
  */
  std::function<void(output_mode, int32_t, int32_t, int32_t)> &on_mode();

  /** \brief sent all information about output

	This event is sent after all other properties have been
	sent after binding to the output object and after any
	other property changes done after that. This allows
	changes to the output properties to be seen as
	atomic, even if they happen via multiple events.
      
  */
  std::function<void()> &on_done();

  /** \brief output scaling properties
      \param factor scaling factor of output

	This event contains scaling geometry information
	that is not in the geometry event. It may be sent after
	binding the output object or if the output scale changes
	later. If it is not sent, the client should assume a
	scale of 1.

	A scale larger than 1 means that the compositor will
	automatically scale surface buffers by this amount
	when rendering. This is used for very high resolution
	displays where applications rendering at the native
	resolution would be too small to be legible.

	It is intended that scaling aware clients track the
	current output of a surface, and if it is on a scaled
	output it should use wl_surface.set_buffer_scale with
	the scale of the output. That way the compositor can
	avoid scaling the surface, and the client can supply
	a higher detail image.
      
  */
  std::function<void(int32_t)> &on_scale();

};

/** \brief subpixel geometry information

	This enumeration describes how the physical
	pixels on an output are laid out.
      
  */
enum class output_subpixel : uint32_t
  {
  /** \brief unknown geometry */
  unknown = 0,
  /** \brief no geometry */
  none = 1,
  /** \brief horizontal RGB */
  horizontal_rgb = 2,
  /** \brief horizontal BGR */
  horizontal_bgr = 3,
  /** \brief vertical RGB */
  vertical_rgb = 4,
  /** \brief vertical BGR */
  vertical_bgr = 5
};

/** \brief transform from framebuffer to output

	This describes the transform that a compositor will apply to a
	surface to compensate for the rotation or mirroring of an
	output device.

	The flipped values correspond to an initial flip around a
	vertical axis followed by rotation.

	The purpose is mainly to allow clients to render accordingly and
	tell the compositor, so that for fullscreen surfaces, the
	compositor will still be able to scan out directly from client
	surfaces.
      
  */
struct output_transform : public detail::bitfield<3, 20>
{
  output_transform(const detail::bitfield<3, 20> &b)
    : detail::bitfield<3, 20>(b) {}
  output_transform(const uint32_t value)
    : detail::bitfield<3, 20>(value) {}
  /** \brief no transform */
  static const detail::bitfield<3, 20> normal;
  /** \brief 90 degrees counter-clockwise */
  static const detail::bitfield<3, 20> _90;
  /** \brief 180 degrees counter-clockwise */
  static const detail::bitfield<3, 20> _180;
  /** \brief 270 degrees counter-clockwise */
  static const detail::bitfield<3, 20> _270;
  /** \brief 180 degree flip around a vertical axis */
  static const detail::bitfield<3, 20> flipped;
  /** \brief flip and rotate 90 degrees counter-clockwise */
  static const detail::bitfield<3, 20> flipped_90;
  /** \brief flip and rotate 180 degrees counter-clockwise */
  static const detail::bitfield<3, 20> flipped_180;
  /** \brief flip and rotate 270 degrees counter-clockwise */
  static const detail::bitfield<3, 20> flipped_270;
};

/** \brief mode information

	These flags describe properties of an output mode.
	They are used in the flags bitfield of the mode event.
      
  */
struct output_mode : public detail::bitfield<2, 21>
{
  output_mode(const detail::bitfield<2, 21> &b)
    : detail::bitfield<2, 21>(b) {}
  output_mode(const uint32_t value)
    : detail::bitfield<2, 21>(value) {}
  /** \brief indicates this is the current mode */
  static const detail::bitfield<2, 21> current;
  /** \brief indicates this is the preferred mode */
  static const detail::bitfield<2, 21> preferred;
};


/** \brief region interface

      A region object describes an area.

      Region objects are used to describe the opaque and input
      regions of a surface.
    
*/
class region_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  region_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  region_t();
  explicit region_t(const proxy_t &proxy);
  region_t(wl_region *p, wrapper_type t = wrapper_type::standard);

  region_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_region*() const;

  /** \brief add rectangle to region
      \param x region-local x coordinate
      \param y region-local y coordinate
      \param width rectangle width
      \param height rectangle height

	Add the specified rectangle to the region.
      
  */
  void add(int32_t x, int32_t y, int32_t width, int32_t height);

  /** \brief Minimum protocol version required for the \ref add function
  */
  static constexpr std::uint32_t add_since_version = 1;

  /** \brief subtract rectangle from region
      \param x region-local x coordinate
      \param y region-local y coordinate
      \param width rectangle width
      \param height rectangle height

	Subtract the specified rectangle from the region.
      
  */
  void subtract(int32_t x, int32_t y, int32_t width, int32_t height);

  /** \brief Minimum protocol version required for the \ref subtract function
  */
  static constexpr std::uint32_t subtract_since_version = 1;

};


/** \brief sub-surface compositing

      The global interface exposing sub-surface compositing capabilities.
      A wl_surface, that has sub-surfaces associated, is called the
      parent surface. Sub-surfaces can be arbitrarily nested and create
      a tree of sub-surfaces.

      The root surface in a tree of sub-surfaces is the main
      surface. The main surface cannot be a sub-surface, because
      sub-surfaces must always have a parent.

      A main surface with its sub-surfaces forms a (compound) window.
      For window management purposes, this set of wl_surface objects is
      to be considered as a single window, and it should also behave as
      such.

      The aim of sub-surfaces is to offload some of the compositing work
      within a window from clients to the compositor. A prime example is
      a video player with decorations and video in separate wl_surface
      objects. This should allow the compositor to pass YUV video buffer
      processing to dedicated overlay hardware when possible.
    
*/
class subcompositor_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  subcompositor_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  subcompositor_t();
  explicit subcompositor_t(const proxy_t &proxy);
  subcompositor_t(wl_subcompositor *p, wrapper_type t = wrapper_type::standard);

  subcompositor_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_subcompositor*() const;

  /** \brief give a surface the role sub-surface
      \return the new sub-surface object ID
      \param surface the surface to be turned into a sub-surface
      \param parent the parent surface

	Create a sub-surface interface for the given surface, and
	associate it with the given parent surface. This turns a
	plain wl_surface into a sub-surface.

	The to-be sub-surface must not already have another role, and it
	must not have an existing wl_subsurface object. Otherwise a protocol
	error is raised.

	Adding sub-surfaces to a parent is a double-buffered operation on the
	parent (see wl_surface.commit). The effect of adding a sub-surface
	becomes visible on the next time the state of the parent surface is
	applied.

	This request modifies the behaviour of wl_surface.commit request on
	the sub-surface, see the documentation on wl_subsurface interface.
      
  */
  subsurface_t get_subsurface(surface_t surface, surface_t parent);

  /** \brief Minimum protocol version required for the \ref get_subsurface function
  */
  static constexpr std::uint32_t get_subsurface_since_version = 1;

};

/** \brief 

  */
enum class subcompositor_error : uint32_t
  {
  /** \brief the to-be sub-surface is invalid */
  bad_surface = 0
};


/** \brief sub-surface interface to a wl_surface

      An additional interface to a wl_surface object, which has been
      made a sub-surface. A sub-surface has one parent surface. A
      sub-surface's size and position are not limited to that of the parent.
      Particularly, a sub-surface is not automatically clipped to its
      parent's area.

      A sub-surface becomes mapped, when a non-NULL wl_buffer is applied
      and the parent surface is mapped. The order of which one happens
      first is irrelevant. A sub-surface is hidden if the parent becomes
      hidden, or if a NULL wl_buffer is applied. These rules apply
      recursively through the tree of surfaces.

      The behaviour of a wl_surface.commit request on a sub-surface
      depends on the sub-surface's mode. The possible modes are
      synchronized and desynchronized, see methods
      wl_subsurface.set_sync and wl_subsurface.set_desync. Synchronized
      mode caches the wl_surface state to be applied when the parent's
      state gets applied, and desynchronized mode applies the pending
      wl_surface state directly. A sub-surface is initially in the
      synchronized mode.

      Sub-surfaces have also other kind of state, which is managed by
      wl_subsurface requests, as opposed to wl_surface requests. This
      state includes the sub-surface position relative to the parent
      surface (wl_subsurface.set_position), and the stacking order of
      the parent and its sub-surfaces (wl_subsurface.place_above and
      .place_below). This state is applied when the parent surface's
      wl_surface state is applied, regardless of the sub-surface's mode.
      As the exception, set_sync and set_desync are effective immediately.

      The main surface can be thought to be always in desynchronized mode,
      since it does not have a parent in the sub-surfaces sense.

      Even if a sub-surface is in desynchronized mode, it will behave as
      in synchronized mode, if its parent surface behaves as in
      synchronized mode. This rule is applied recursively throughout the
      tree of surfaces. This means, that one can set a sub-surface into
      synchronized mode, and then assume that all its child and grand-child
      sub-surfaces are synchronized, too, without explicitly setting them.

      If the wl_surface associated with the wl_subsurface is destroyed, the
      wl_subsurface object becomes inert. Note, that destroying either object
      takes effect immediately. If you need to synchronize the removal
      of a sub-surface to the parent surface update, unmap the sub-surface
      first by attaching a NULL wl_buffer, update parent, and then destroy
      the sub-surface.

      If the parent wl_surface object is destroyed, the sub-surface is
      unmapped.
    
*/
class subsurface_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  subsurface_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  subsurface_t();
  explicit subsurface_t(const proxy_t &proxy);
  subsurface_t(wl_subsurface *p, wrapper_type t = wrapper_type::standard);

  subsurface_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wl_subsurface*() const;

  /** \brief reposition the sub-surface
      \param x x coordinate in the parent surface
      \param y y coordinate in the parent surface

	This schedules a sub-surface position change.
	The sub-surface will be moved so that its origin (top left
	corner pixel) will be at the location x, y of the parent surface
	coordinate system. The coordinates are not restricted to the parent
	surface area. Negative values are allowed.

	The scheduled coordinates will take effect whenever the state of the
	parent surface is applied. When this happens depends on whether the
	parent surface is in synchronized mode or not. See
	wl_subsurface.set_sync and wl_subsurface.set_desync for details.

	If more than one set_position request is invoked by the client before
	the commit of the parent surface, the position of a new request always
	replaces the scheduled position from any previous request.

	The initial position is 0, 0.
      
  */
  void set_position(int32_t x, int32_t y);

  /** \brief Minimum protocol version required for the \ref set_position function
  */
  static constexpr std::uint32_t set_position_since_version = 1;

  /** \brief restack the sub-surface
      \param sibling the reference surface

	This sub-surface is taken from the stack, and put back just
	above the reference surface, changing the z-order of the sub-surfaces.
	The reference surface must be one of the sibling surfaces, or the
	parent surface. Using any other surface, including this sub-surface,
	will cause a protocol error.

	The z-order is double-buffered. Requests are handled in order and
	applied immediately to a pending state. The final pending state is
	copied to the active state the next time the state of the parent
	surface is applied. When this happens depends on whether the parent
	surface is in synchronized mode or not. See wl_subsurface.set_sync and
	wl_subsurface.set_desync for details.

	A new sub-surface is initially added as the top-most in the stack
	of its siblings and parent.
      
  */
  void place_above(surface_t sibling);

  /** \brief Minimum protocol version required for the \ref place_above function
  */
  static constexpr std::uint32_t place_above_since_version = 1;

  /** \brief restack the sub-surface
      \param sibling the reference surface

	The sub-surface is placed just below the reference surface.
	See wl_subsurface.place_above.
      
  */
  void place_below(surface_t sibling);

  /** \brief Minimum protocol version required for the \ref place_below function
  */
  static constexpr std::uint32_t place_below_since_version = 1;

  /** \brief set sub-surface to synchronized mode

	Change the commit behaviour of the sub-surface to synchronized
	mode, also described as the parent dependent mode.

	In synchronized mode, wl_surface.commit on a sub-surface will
	accumulate the committed state in a cache, but the state will
	not be applied and hence will not change the compositor output.
	The cached state is applied to the sub-surface immediately after
	the parent surface's state is applied. This ensures atomic
	updates of the parent and all its synchronized sub-surfaces.
	Applying the cached state will invalidate the cache, so further
	parent surface commits do not (re-)apply old state.

	See wl_subsurface for the recursive effect of this mode.
      
  */
  void set_sync();

  /** \brief Minimum protocol version required for the \ref set_sync function
  */
  static constexpr std::uint32_t set_sync_since_version = 1;

  /** \brief set sub-surface to desynchronized mode

	Change the commit behaviour of the sub-surface to desynchronized
	mode, also described as independent or freely running mode.

	In desynchronized mode, wl_surface.commit on a sub-surface will
	apply the pending state directly, without caching, as happens
	normally with a wl_surface. Calling wl_surface.commit on the
	parent surface has no effect on the sub-surface's wl_surface
	state. This mode allows a sub-surface to be updated on its own.

	If cached state exists when wl_surface.commit is called in
	desynchronized mode, the pending state is added to the cached
	state, and applied as a whole. This invalidates the cache.

	Note: even if a sub-surface is set to desynchronized, a parent
	sub-surface may override it to behave as synchronized. For details,
	see wl_subsurface.

	If a surface's parent surface behaves as desynchronized, then
	the cached state is applied on set_desync.
      
  */
  void set_desync();

  /** \brief Minimum protocol version required for the \ref set_desync function
  */
  static constexpr std::uint32_t set_desync_since_version = 1;

};

/** \brief 

  */
enum class subsurface_error : uint32_t
  {
  /** \brief wl_surface is not a sibling or the parent */
  bad_surface = 0
};



}
