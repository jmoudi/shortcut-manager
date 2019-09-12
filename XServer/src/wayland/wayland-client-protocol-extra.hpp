#pragma once

#include <array>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include <wayland-client.hpp>

struct wp_presentation;
struct wp_presentation_feedback;
struct wp_viewporter;
struct wp_viewport;
struct xdg_wm_base;
struct xdg_positioner;
struct xdg_surface;
struct xdg_toplevel;
struct xdg_popup;

namespace wayland
{
class presentation_t;
enum class presentation_error : uint32_t;
class presentation_feedback_t;
struct presentation_feedback_kind;
class viewporter_t;
enum class viewporter_error : uint32_t;
class viewport_t;
enum class viewport_error : uint32_t;
class xdg_wm_base_t;
enum class xdg_wm_base_error : uint32_t;
class xdg_positioner_t;
enum class xdg_positioner_error : uint32_t;
enum class xdg_positioner_anchor : uint32_t;
enum class xdg_positioner_gravity : uint32_t;
struct xdg_positioner_constraint_adjustment;
class xdg_surface_t;
enum class xdg_surface_error : uint32_t;
class xdg_toplevel_t;
struct xdg_toplevel_resize_edge;
enum class xdg_toplevel_state : uint32_t;
class xdg_popup_t;
enum class xdg_popup_error : uint32_t;

namespace detail
{
  extern const wl_interface presentation_interface;
  extern const wl_interface presentation_feedback_interface;
  extern const wl_interface viewporter_interface;
  extern const wl_interface viewport_interface;
  extern const wl_interface xdg_wm_base_interface;
  extern const wl_interface xdg_positioner_interface;
  extern const wl_interface xdg_surface_interface;
  extern const wl_interface xdg_toplevel_interface;
  extern const wl_interface xdg_popup_interface;
}

/** \brief timed presentation related wl_surface requests


      The main feature of this interface is accurate presentation
      timing feedback to ensure smooth video playback while maintaining
      audio/video synchronization. Some features use the concept of a
      presentation clock, which is defined in the
      presentation.clock_id event.

      A content update for a wl_surface is submitted by a
      wl_surface.commit request. Request 'feedback' associates with
      the wl_surface.commit and provides feedback on the content
      update, particularly the final realized presentation time.


*/
class presentation_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(uint32_t)> clock_id;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  presentation_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  presentation_t();
  explicit presentation_t(const proxy_t &proxy);
  presentation_t(wp_presentation *p, wrapper_type t = wrapper_type::standard);

  presentation_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wp_presentation*() const;

  /** \brief request presentation feedback information
      \return new feedback object
      \param surface target surface

        Request presentation feedback for the current content submission
        on the given surface. This creates a new presentation_feedback
        object, which will deliver the feedback information once. If
        multiple presentation_feedback objects are created for the same
        submission, they will all deliver the same information.

        For details on what information is returned, see the
        presentation_feedback interface.
      
  */
  presentation_feedback_t feedback(surface_t surface);

  /** \brief Minimum protocol version required for the \ref feedback function
  */
  static constexpr std::uint32_t feedback_since_version = 1;

  /** \brief clock ID for timestamps
      \param clk_id platform clock identifier

        This event tells the client in which clock domain the
        compositor interprets the timestamps used by the presentation
        extension. This clock is called the presentation clock.

        The compositor sends this event when the client binds to the
        presentation interface. The presentation clock does not change
        during the lifetime of the client connection.

        The clock identifier is platform dependent. On Linux/glibc,
        the identifier value is one of the clockid_t values accepted
        by clock_gettime(). clock_gettime() is defined by
        POSIX.1-2001.

        Timestamps in this clock domain are expressed as tv_sec_hi,
        tv_sec_lo, tv_nsec triples, each component being an unsigned
        32-bit value. Whole seconds are in tv_sec which is a 64-bit
        value combined from tv_sec_hi and tv_sec_lo, and the
        additional fractional part in tv_nsec as nanoseconds. Hence,
        for valid timestamps tv_nsec must be in [0, 999999999].

        Note that clock_id applies only to the presentation clock,
        and implies nothing about e.g. the timestamps used in the
        Wayland core protocol input events.

        Compositors should prefer a clock which does not jump and is
        not slewed e.g. by NTP. The absolute value of the clock is
        irrelevant. Precision of one millisecond or better is
        recommended. Clients must be able to query the current clock
        value directly, not by asking the compositor.
      
  */
  std::function<void(uint32_t)> &on_clock_id();

};

/** \brief fatal presentation errors

        These fatal protocol errors may be emitted in response to
        illegal presentation requests.
      
  */
enum class presentation_error : uint32_t
  {
  /** \brief invalid value in tv_nsec */
  invalid_timestamp = 0,
  /** \brief invalid flag */
  invalid_flag = 1
};


/** \brief presentation time feedback event

      A presentation_feedback object returns an indication that a
      wl_surface content update has become visible to the user.
      One object corresponds to one content update submission
      (wl_surface.commit). There are two possible outcomes: the
      content update is presented to the user, and a presentation
      timestamp delivered; or, the user did not see the content
      update because it was superseded or its surface destroyed,
      and the content update is discarded.

      Once a presentation_feedback object has delivered a 'presented'
      or 'discarded' event it is automatically destroyed.
    
*/
class presentation_feedback_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(output_t)> sync_output;
    std::function<void(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, presentation_feedback_kind)> presented;
    std::function<void()> discarded;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  presentation_feedback_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  presentation_feedback_t();
  explicit presentation_feedback_t(const proxy_t &proxy);
  presentation_feedback_t(wp_presentation_feedback *p, wrapper_type t = wrapper_type::standard);

  presentation_feedback_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wp_presentation_feedback*() const;

  /** \brief presentation synchronized to this output
      \param output presentation output

        As presentation can be synchronized to only one output at a
        time, this event tells which output it was. This event is only
        sent prior to the presented event.

        As clients may bind to the same global wl_output multiple
        times, this event is sent for each bound instance that matches
        the synchronized output. If a client has not bound to the
        right wl_output global at all, this event is not sent.
      
  */
  std::function<void(output_t)> &on_sync_output();

  /** \brief the content update was displayed
      \param tv_sec_hi high 32 bits of the seconds part of the presentation timestamp
      \param tv_sec_lo low 32 bits of the seconds part of the presentation timestamp
      \param tv_nsec nanoseconds part of the presentation timestamp
      \param refresh nanoseconds till next refresh
      \param seq_hi high 32 bits of refresh counter
      \param seq_lo low 32 bits of refresh counter
      \param flags combination of 'kind' values

        The associated content update was displayed to the user at the
        indicated time (tv_sec_hi/lo, tv_nsec). For the interpretation of
        the timestamp, see presentation.clock_id event.

        The timestamp corresponds to the time when the content update
        turned into light the first time on the surface's main output.
        Compositors may approximate this from the framebuffer flip
        completion events from the system, and the latency of the
        physical display path if known.

        This event is preceded by all related sync_output events
        telling which output's refresh cycle the feedback corresponds
        to, i.e. the main output for the surface. Compositors are
        recommended to choose the output containing the largest part
        of the wl_surface, or keeping the output they previously
        chose. Having a stable presentation output association helps
        clients predict future output refreshes (vblank).

        The 'refresh' argument gives the compositor's prediction of how
        many nanoseconds after tv_sec, tv_nsec the very next output
        refresh may occur. This is to further aid clients in
        predicting future refreshes, i.e., estimating the timestamps
        targeting the next few vblanks. If such prediction cannot
        usefully be done, the argument is zero.

        If the output does not have a constant refresh rate, explicit
        video mode switches excluded, then the refresh argument must
        be zero.

        The 64-bit value combined from seq_hi and seq_lo is the value
        of the output's vertical retrace counter when the content
        update was first scanned out to the display. This value must
        be compatible with the definition of MSC in
        GLX_OML_sync_control specification. Note, that if the display
        path has a non-zero latency, the time instant specified by
        this counter may differ from the timestamp's.

        If the output does not have a concept of vertical retrace or a
        refresh cycle, or the output device is self-refreshing without
        a way to query the refresh count, then the arguments seq_hi
        and seq_lo must be zero.
      
  */
  std::function<void(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, presentation_feedback_kind)> &on_presented();

  /** \brief the content update was not displayed

        The content update was never displayed to the user.
      
  */
  std::function<void()> &on_discarded();

};

/** \brief bitmask of flags in presented event

        These flags provide information about how the presentation of
        the related content update was done. The intent is to help
        clients assess the reliability of the feedback and the visual
        quality with respect to possible tearing and timings. The
        flags are:

        VSYNC:
        The presentation was synchronized to the "vertical retrace" by
        the display hardware such that tearing does not happen.
        Relying on user space scheduling is not acceptable for this
        flag. If presentation is done by a copy to the active
        frontbuffer, then it must guarantee that tearing cannot
        happen.

        HW_CLOCK:
        The display hardware provided measurements that the hardware
        driver converted into a presentation timestamp. Sampling a
        clock in user space is not acceptable for this flag.

        HW_COMPLETION:
        The display hardware signalled that it started using the new
        image content. The opposite of this is e.g. a timer being used
        to guess when the display hardware has switched to the new
        image content.

        ZERO_COPY:
        The presentation of this update was done zero-copy. This means
        the buffer from the client was given to display hardware as
        is, without copying it. Compositing with OpenGL counts as
        copying, even if textured directly from the client buffer.
        Possible zero-copy cases include direct scanout of a
        fullscreen surface and a surface on a hardware overlay.
      
  */
struct presentation_feedback_kind : public detail::bitfield<4, 1>
{
  presentation_feedback_kind(const detail::bitfield<4, 1> &b)
    : detail::bitfield<4, 1>(b) {}
  presentation_feedback_kind(const uint32_t value)
    : detail::bitfield<4, 1>(value) {}
  /** \brief presentation was vsync'd */
  static const detail::bitfield<4, 1> vsync;
  /** \brief hardware provided the presentation timestamp */
  static const detail::bitfield<4, 1> hw_clock;
  /** \brief hardware signalled the start of the presentation */
  static const detail::bitfield<4, 1> hw_completion;
  /** \brief presentation was done zero-copy */
  static const detail::bitfield<4, 1> zero_copy;
};


/** \brief surface cropping and scaling

      The global interface exposing surface cropping and scaling
      capabilities is used to instantiate an interface extension for a
      wl_surface object. This extended interface will then allow
      cropping and scaling the surface contents, effectively
      disconnecting the direct relationship between the buffer and the
      surface size.
    
*/
class viewporter_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  viewporter_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  viewporter_t();
  explicit viewporter_t(const proxy_t &proxy);
  viewporter_t(wp_viewporter *p, wrapper_type t = wrapper_type::standard);

  viewporter_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wp_viewporter*() const;

  /** \brief extend surface interface for crop and scale
      \return the new viewport interface id
      \param surface the surface

	Instantiate an interface extension for the given wl_surface to
	crop and scale its content. If the given wl_surface already has
	a wp_viewport object associated, the viewport_exists
	protocol error is raised.
      
  */
  viewport_t get_viewport(surface_t surface);

  /** \brief Minimum protocol version required for the \ref get_viewport function
  */
  static constexpr std::uint32_t get_viewport_since_version = 1;

};

/** \brief 

  */
enum class viewporter_error : uint32_t
  {
  /** \brief the surface already has a viewport object associated */
  viewport_exists = 0
};


/** \brief crop and scale interface to a wl_surface

      An additional interface to a wl_surface object, which allows the
      client to specify the cropping and scaling of the surface
      contents.

      This interface works with two concepts: the source rectangle (src_x,
      src_y, src_width, src_height), and the destination size (dst_width,
      dst_height). The contents of the source rectangle are scaled to the
      destination size, and content outside the source rectangle is ignored.
      This state is double-buffered, and is applied on the next
      wl_surface.commit.

      The two parts of crop and scale state are independent: the source
      rectangle, and the destination size. Initially both are unset, that
      is, no scaling is applied. The whole of the current wl_buffer is
      used as the source, and the surface size is as defined in
      wl_surface.attach.

      If the destination size is set, it causes the surface size to become
      dst_width, dst_height. The source (rectangle) is scaled to exactly
      this size. This overrides whatever the attached wl_buffer size is,
      unless the wl_buffer is NULL. If the wl_buffer is NULL, the surface
      has no content and therefore no size. Otherwise, the size is always
      at least 1x1 in surface local coordinates.

      If the source rectangle is set, it defines what area of the wl_buffer is
      taken as the source. If the source rectangle is set and the destination
      size is not set, then src_width and src_height must be integers, and the
      surface size becomes the source rectangle size. This results in cropping
      without scaling. If src_width or src_height are not integers and
      destination size is not set, the bad_size protocol error is raised when
      the surface state is applied.

      The coordinate transformations from buffer pixel coordinates up to
      the surface-local coordinates happen in the following order:
        1. buffer_transform (wl_surface.set_buffer_transform)
        2. buffer_scale (wl_surface.set_buffer_scale)
        3. crop and scale (wp_viewport.set*)
      This means, that the source rectangle coordinates of crop and scale
      are given in the coordinates after the buffer transform and scale,
      i.e. in the coordinates that would be the surface-local coordinates
      if the crop and scale was not applied.

      If src_x or src_y are negative, the bad_value protocol error is raised.
      Otherwise, if the source rectangle is partially or completely outside of
      the non-NULL wl_buffer, then the out_of_buffer protocol error is raised
      when the surface state is applied. A NULL wl_buffer does not raise the
      out_of_buffer error.

      The x, y arguments of wl_surface.attach are applied as normal to
      the surface. They indicate how many pixels to remove from the
      surface size from the left and the top. In other words, they are
      still in the surface-local coordinate system, just like dst_width
      and dst_height are.

      If the wl_surface associated with the wp_viewport is destroyed,
      all wp_viewport requests except 'destroy' raise the protocol error
      no_surface.

      If the wp_viewport object is destroyed, the crop and scale
      state is removed from the wl_surface. The change will be applied
      on the next wl_surface.commit.
    
*/
class viewport_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  viewport_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  viewport_t();
  explicit viewport_t(const proxy_t &proxy);
  viewport_t(wp_viewport *p, wrapper_type t = wrapper_type::standard);

  viewport_t proxy_create_wrapper();

  static const std::string interface_name;

  operator wp_viewport*() const;

  /** \brief set the source rectangle for cropping
      \param x source rectangle x
      \param y source rectangle y
      \param width source rectangle width
      \param height source rectangle height

	Set the source rectangle of the associated wl_surface. See
	wp_viewport for the description, and relation to the wl_buffer
	size.

	If all of x, y, width and height are -1.0, the source rectangle is
	unset instead. Any other set of values where width or height are zero
	or negative, or x or y are negative, raise the bad_value protocol
	error.

	The crop and scale state is double-buffered state, and will be
	applied on the next wl_surface.commit.
      
  */
  void set_source(double x, double y, double width, double height);

  /** \brief Minimum protocol version required for the \ref set_source function
  */
  static constexpr std::uint32_t set_source_since_version = 1;

  /** \brief set the surface size for scaling
      \param width surface width
      \param height surface height

	Set the destination size of the associated wl_surface. See
	wp_viewport for the description, and relation to the wl_buffer
	size.

	If width is -1 and height is -1, the destination size is unset
	instead. Any other pair of values for width and height that
	contains zero or negative values raises the bad_value protocol
	error.

	The crop and scale state is double-buffered state, and will be
	applied on the next wl_surface.commit.
      
  */
  void set_destination(int32_t width, int32_t height);

  /** \brief Minimum protocol version required for the \ref set_destination function
  */
  static constexpr std::uint32_t set_destination_since_version = 1;

};

/** \brief 

  */
enum class viewport_error : uint32_t
  {
  /** \brief negative or zero values in width or height */
  bad_value = 0,
  /** \brief destination size is not integer */
  bad_size = 1,
  /** \brief source rectangle extends outside of the content area */
  out_of_buffer = 2,
  /** \brief the wl_surface was destroyed */
  no_surface = 3
};


/** \brief create desktop-style surfaces

      The xdg_wm_base interface is exposed as a global object enabling clients
      to turn their wl_surfaces into windows in a desktop environment. It
      defines the basic functionality needed for clients and the compositor to
      create windows that can be dragged, resized, maximized, etc, as well as
      creating transient windows such as popup menus.
    
*/
class xdg_wm_base_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(uint32_t)> ping;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  xdg_wm_base_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  xdg_wm_base_t();
  explicit xdg_wm_base_t(const proxy_t &proxy);
  xdg_wm_base_t(xdg_wm_base *p, wrapper_type t = wrapper_type::standard);

  xdg_wm_base_t proxy_create_wrapper();

  static const std::string interface_name;

  operator xdg_wm_base*() const;

  /** \brief create a positioner object

	Create a positioner object. A positioner object is used to position
	surfaces relative to some parent surface. See the interface description
	and xdg_surface.get_popup for details.
      
  */
  xdg_positioner_t create_positioner();

  /** \brief Minimum protocol version required for the \ref create_positioner function
  */
  static constexpr std::uint32_t create_positioner_since_version = 1;

  /** \brief create a shell surface from a surface
      \param surface 

	This creates an xdg_surface for the given surface. While xdg_surface
	itself is not a role, the corresponding surface may only be assigned
	a role extending xdg_surface, such as xdg_toplevel or xdg_popup.

	This creates an xdg_surface for the given surface. An xdg_surface is
	used as basis to define a role to a given surface, such as xdg_toplevel
	or xdg_popup. It also manages functionality shared between xdg_surface
	based surface roles.

	See the documentation of xdg_surface for more details about what an
	xdg_surface is and how it is used.
      
  */
  xdg_surface_t get_xdg_surface(surface_t surface);

  /** \brief Minimum protocol version required for the \ref get_xdg_surface function
  */
  static constexpr std::uint32_t get_xdg_surface_since_version = 1;

  /** \brief respond to a ping event
      \param serial serial of the ping event

	A client must respond to a ping event with a pong request or
	the client may be deemed unresponsive. See xdg_wm_base.ping.
      
  */
  void pong(uint32_t serial);

  /** \brief Minimum protocol version required for the \ref pong function
  */
  static constexpr std::uint32_t pong_since_version = 1;

  /** \brief check if the client is alive
      \param serial pass this to the pong request

	The ping event asks the client if it's still alive. Pass the
	serial specified in the event back to the compositor by sending
	a "pong" request back with the specified serial. See xdg_wm_base.pong.

	Compositors can use this to determine if the client is still
	alive. It's unspecified what will happen if the client doesn't
	respond to the ping request, or in what timeframe. Clients should
	try to respond in a reasonable amount of time.

	A compositor is free to ping in any way it wants, but a client must
	always respond to any xdg_wm_base object it created.
      
  */
  std::function<void(uint32_t)> &on_ping();

};

/** \brief 

  */
enum class xdg_wm_base_error : uint32_t
  {
  /** \brief given wl_surface has another role */
  role = 0,
  /** \brief xdg_wm_base was destroyed before children */
  defunct_surfaces = 1,
  /** \brief the client tried to map or destroy a non-topmost popup */
  not_the_topmost_popup = 2,
  /** \brief the client specified an invalid popup parent surface */
  invalid_popup_parent = 3,
  /** \brief the client provided an invalid surface state */
  invalid_surface_state = 4,
  /** \brief the client provided an invalid positioner */
  invalid_positioner = 5
};


/** \brief child surface positioner

      The xdg_positioner provides a collection of rules for the placement of a
      child surface relative to a parent surface. Rules can be defined to ensure
      the child surface remains within the visible area's borders, and to
      specify how the child surface changes its position, such as sliding along
      an axis, or flipping around a rectangle. These positioner-created rules are
      constrained by the requirement that a child surface must intersect with or
      be at least partially adjacent to its parent surface.

      See the various requests for details about possible rules.

      At the time of the request, the compositor makes a copy of the rules
      specified by the xdg_positioner. Thus, after the request is complete the
      xdg_positioner object can be destroyed or reused; further changes to the
      object will have no effect on previous usages.

      For an xdg_positioner object to be considered complete, it must have a
      non-zero size set by set_size, and a non-zero anchor rectangle set by
      set_anchor_rect. Passing an incomplete xdg_positioner object when
      positioning a surface raises an error.
    
*/
class xdg_positioner_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  xdg_positioner_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  xdg_positioner_t();
  explicit xdg_positioner_t(const proxy_t &proxy);
  xdg_positioner_t(xdg_positioner *p, wrapper_type t = wrapper_type::standard);

  xdg_positioner_t proxy_create_wrapper();

  static const std::string interface_name;

  operator xdg_positioner*() const;

  /** \brief set the size of the to-be positioned rectangle
      \param width width of positioned rectangle
      \param height height of positioned rectangle

	Set the size of the surface that is to be positioned with the positioner
	object. The size is in surface-local coordinates and corresponds to the
	window geometry. See xdg_surface.set_window_geometry.

	If a zero or negative size is set the invalid_input error is raised.
      
  */
  void set_size(int32_t width, int32_t height);

  /** \brief Minimum protocol version required for the \ref set_size function
  */
  static constexpr std::uint32_t set_size_since_version = 1;

  /** \brief set the anchor rectangle within the parent surface
      \param x x position of anchor rectangle
      \param y y position of anchor rectangle
      \param width width of anchor rectangle
      \param height height of anchor rectangle

	Specify the anchor rectangle within the parent surface that the child
	surface will be placed relative to. The rectangle is relative to the
	window geometry as defined by xdg_surface.set_window_geometry of the
	parent surface.

	When the xdg_positioner object is used to position a child surface, the
	anchor rectangle may not extend outside the window geometry of the
	positioned child's parent surface.

	If a negative size is set the invalid_input error is raised.
      
  */
  void set_anchor_rect(int32_t x, int32_t y, int32_t width, int32_t height);

  /** \brief Minimum protocol version required for the \ref set_anchor_rect function
  */
  static constexpr std::uint32_t set_anchor_rect_since_version = 1;

  /** \brief set anchor rectangle anchor
      \param anchor anchor

	Defines the anchor point for the anchor rectangle. The specified anchor
	is used derive an anchor point that the child surface will be
	positioned relative to. If a corner anchor is set (e.g. 'top_left' or
	'bottom_right'), the anchor point will be at the specified corner;
	otherwise, the derived anchor point will be centered on the specified
	edge, or in the center of the anchor rectangle if no edge is specified.
      
  */
  void set_anchor(xdg_positioner_anchor anchor);

  /** \brief Minimum protocol version required for the \ref set_anchor function
  */
  static constexpr std::uint32_t set_anchor_since_version = 1;

  /** \brief set child surface gravity
      \param gravity gravity direction

	Defines in what direction a surface should be positioned, relative to
	the anchor point of the parent surface. If a corner gravity is
	specified (e.g. 'bottom_right' or 'top_left'), then the child surface
	will be placed towards the specified gravity; otherwise, the child
	surface will be centered over the anchor point on any axis that had no
	gravity specified.
      
  */
  void set_gravity(xdg_positioner_gravity gravity);

  /** \brief Minimum protocol version required for the \ref set_gravity function
  */
  static constexpr std::uint32_t set_gravity_since_version = 1;

  /** \brief set the adjustment to be done when constrained
      \param constraint_adjustment bit mask of constraint adjustments

	Specify how the window should be positioned if the originally intended
	position caused the surface to be constrained, meaning at least
	partially outside positioning boundaries set by the compositor. The
	adjustment is set by constructing a bitmask describing the adjustment to
	be made when the surface is constrained on that axis.

	If no bit for one axis is set, the compositor will assume that the child
	surface should not change its position on that axis when constrained.

	If more than one bit for one axis is set, the order of how adjustments
	are applied is specified in the corresponding adjustment descriptions.

	The default adjustment is none.
      
  */
  void set_constraint_adjustment(xdg_positioner_constraint_adjustment constraint_adjustment);

  /** \brief Minimum protocol version required for the \ref set_constraint_adjustment function
  */
  static constexpr std::uint32_t set_constraint_adjustment_since_version = 1;

  /** \brief set surface position offset
      \param x surface position x offset
      \param y surface position y offset

	Specify the surface position offset relative to the position of the
	anchor on the anchor rectangle and the anchor on the surface. For
	example if the anchor of the anchor rectangle is at (x, y), the surface
	has the gravity bottom|right, and the offset is (ox, oy), the calculated
	surface position will be (x + ox, y + oy). The offset position of the
	surface is the one used for constraint testing. See
	set_constraint_adjustment.

	An example use case is placing a popup menu on top of a user interface
	element, while aligning the user interface element of the parent surface
	with some user interface element placed somewhere in the popup surface.
      
  */
  void set_offset(int32_t x, int32_t y);

  /** \brief Minimum protocol version required for the \ref set_offset function
  */
  static constexpr std::uint32_t set_offset_since_version = 1;

};

/** \brief 

  */
enum class xdg_positioner_error : uint32_t
  {
  /** \brief invalid input provided */
  invalid_input = 0
};

/** \brief 

  */
enum class xdg_positioner_anchor : uint32_t
  {
  none = 0,
  top = 1,
  bottom = 2,
  left = 3,
  right = 4,
  top_left = 5,
  bottom_left = 6,
  top_right = 7,
  bottom_right = 8
};

/** \brief 

  */
enum class xdg_positioner_gravity : uint32_t
  {
  none = 0,
  top = 1,
  bottom = 2,
  left = 3,
  right = 4,
  top_left = 5,
  bottom_left = 6,
  top_right = 7,
  bottom_right = 8
};

/** \brief constraint adjustments

	The constraint adjustment value define ways the compositor will adjust
	the position of the surface, if the unadjusted position would result
	in the surface being partly constrained.

	Whether a surface is considered 'constrained' is left to the compositor
	to determine. For example, the surface may be partly outside the
	compositor's defined 'work area', thus necessitating the child surface's
	position be adjusted until it is entirely inside the work area.

	The adjustments can be combined, according to a defined precedence: 1)
	Flip, 2) Slide, 3) Resize.
      
  */
struct xdg_positioner_constraint_adjustment : public detail::bitfield<6, 8>
{
  xdg_positioner_constraint_adjustment(const detail::bitfield<6, 8> &b)
    : detail::bitfield<6, 8>(b) {}
  xdg_positioner_constraint_adjustment(const uint32_t value)
    : detail::bitfield<6, 8>(value) {}
  static const detail::bitfield<6, 8> none;
  static const detail::bitfield<6, 8> slide_x;
  static const detail::bitfield<6, 8> slide_y;
  static const detail::bitfield<6, 8> flip_x;
  static const detail::bitfield<6, 8> flip_y;
  static const detail::bitfield<6, 8> resize_x;
  static const detail::bitfield<6, 8> resize_y;
};


/** \brief desktop user interface surface base interface

      An interface that may be implemented by a wl_surface, for
      implementations that provide a desktop-style user interface.

      It provides a base set of functionality required to construct user
      interface elements requiring management by the compositor, such as
      toplevel windows, menus, etc. The types of functionality are split into
      xdg_surface roles.

      Creating an xdg_surface does not set the role for a wl_surface. In order
      to map an xdg_surface, the client must create a role-specific object
      using, e.g., get_toplevel, get_popup. The wl_surface for any given
      xdg_surface can have at most one role, and may not be assigned any role
      not based on xdg_surface.

      A role must be assigned before any other requests are made to the
      xdg_surface object.

      The client must call wl_surface.commit on the corresponding wl_surface
      for the xdg_surface state to take effect.

      Creating an xdg_surface from a wl_surface which has a buffer attached or
      committed is a client error, and any attempts by a client to attach or
      manipulate a buffer prior to the first xdg_surface.configure call must
      also be treated as errors.

      Mapping an xdg_surface-based role surface is defined as making it
      possible for the surface to be shown by the compositor. Note that
      a mapped surface is not guaranteed to be visible once it is mapped.

      For an xdg_surface to be mapped by the compositor, the following
      conditions must be met:
      (1) the client has assigned an xdg_surface-based role to the surface
      (2) the client has set and committed the xdg_surface state and the
	  role-dependent state to the surface
      (3) the client has committed a buffer to the surface

      A newly-unmapped surface is considered to have met condition (1) out
      of the 3 required conditions for mapping a surface if its role surface
      has not been destroyed.
    
*/
class xdg_surface_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(uint32_t)> configure;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  xdg_surface_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  xdg_surface_t();
  explicit xdg_surface_t(const proxy_t &proxy);
  xdg_surface_t(xdg_surface *p, wrapper_type t = wrapper_type::standard);

  xdg_surface_t proxy_create_wrapper();

  static const std::string interface_name;

  operator xdg_surface*() const;

  /** \brief assign the xdg_toplevel surface role

	This creates an xdg_toplevel object for the given xdg_surface and gives
	the associated wl_surface the xdg_toplevel role.

	See the documentation of xdg_toplevel for more details about what an
	xdg_toplevel is and how it is used.
      
  */
  xdg_toplevel_t get_toplevel();

  /** \brief Minimum protocol version required for the \ref get_toplevel function
  */
  static constexpr std::uint32_t get_toplevel_since_version = 1;

  /** \brief assign the xdg_popup surface role
      \param parent 
      \param positioner 

	This creates an xdg_popup object for the given xdg_surface and gives
	the associated wl_surface the xdg_popup role.

	If null is passed as a parent, a parent surface must be specified using
	some other protocol, before committing the initial state.

	See the documentation of xdg_popup for more details about what an
	xdg_popup is and how it is used.
      
  */
  xdg_popup_t get_popup(xdg_surface_t parent, xdg_positioner_t positioner);

  /** \brief Minimum protocol version required for the \ref get_popup function
  */
  static constexpr std::uint32_t get_popup_since_version = 1;

  /** \brief set the new window geometry
      \param x 
      \param y 
      \param width 
      \param height 

	The window geometry of a surface is its "visible bounds" from the
	user's perspective. Client-side decorations often have invisible
	portions like drop-shadows which should be ignored for the
	purposes of aligning, placing and constraining windows.

	The window geometry is double buffered, and will be applied at the
	time wl_surface.commit of the corresponding wl_surface is called.

	When maintaining a position, the compositor should treat the (x, y)
	coordinate of the window geometry as the top left corner of the window.
	A client changing the (x, y) window geometry coordinate should in
	general not alter the position of the window.

	Once the window geometry of the surface is set, it is not possible to
	unset it, and it will remain the same until set_window_geometry is
	called again, even if a new subsurface or buffer is attached.

	If never set, the value is the full bounds of the surface,
	including any subsurfaces. This updates dynamically on every
	commit. This unset is meant for extremely simple clients.

	The arguments are given in the surface-local coordinate space of
	the wl_surface associated with this xdg_surface.

	The width and height must be greater than zero. Setting an invalid size
	will raise an error. When applied, the effective window geometry will be
	the set window geometry clamped to the bounding rectangle of the
	combined geometry of the surface of the xdg_surface and the associated
	subsurfaces.
      
  */
  void set_window_geometry(int32_t x, int32_t y, int32_t width, int32_t height);

  /** \brief Minimum protocol version required for the \ref set_window_geometry function
  */
  static constexpr std::uint32_t set_window_geometry_since_version = 1;

  /** \brief ack a configure event
      \param serial the serial from the configure event

	When a configure event is received, if a client commits the
	surface in response to the configure event, then the client
	must make an ack_configure request sometime before the commit
	request, passing along the serial of the configure event.

	For instance, for toplevel surfaces the compositor might use this
	information to move a surface to the top left only when the client has
	drawn itself for the maximized or fullscreen state.

	If the client receives multiple configure events before it
	can respond to one, it only has to ack the last configure event.

	A client is not required to commit immediately after sending
	an ack_configure request - it may even ack_configure several times
	before its next surface commit.

	A client may send multiple ack_configure requests before committing, but
	only the last request sent before a commit indicates which configure
	event the client really is responding to.
      
  */
  void ack_configure(uint32_t serial);

  /** \brief Minimum protocol version required for the \ref ack_configure function
  */
  static constexpr std::uint32_t ack_configure_since_version = 1;

  /** \brief suggest a surface change
      \param serial serial of the configure event

	The configure event marks the end of a configure sequence. A configure
	sequence is a set of one or more events configuring the state of the
	xdg_surface, including the final xdg_surface.configure event.

	Where applicable, xdg_surface surface roles will during a configure
	sequence extend this event as a latched state sent as events before the
	xdg_surface.configure event. Such events should be considered to make up
	a set of atomically applied configuration states, where the
	xdg_surface.configure commits the accumulated state.

	Clients should arrange their surface for the new states, and then send
	an ack_configure request with the serial sent in this configure event at
	some point before committing the new surface.

	If the client receives multiple configure events before it can respond
	to one, it is free to discard all but the last event it received.
      
  */
  std::function<void(uint32_t)> &on_configure();

};

/** \brief 

  */
enum class xdg_surface_error : uint32_t
  {
  not_constructed = 1,
  already_constructed = 2,
  unconfigured_buffer = 3
};


/** \brief toplevel surface

      This interface defines an xdg_surface role which allows a surface to,
      among other things, set window-like properties such as maximize,
      fullscreen, and minimize, set application-specific metadata like title and
      id, and well as trigger user interactive operations such as interactive
      resize and move.

      Unmapping an xdg_toplevel means that the surface cannot be shown
      by the compositor until it is explicitly mapped again.
      All active operations (e.g., move, resize) are canceled and all
      attributes (e.g. title, state, stacking, ...) are discarded for
      an xdg_toplevel surface when it is unmapped.

      Attaching a null buffer to a toplevel unmaps the surface.
    
*/
class xdg_toplevel_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(int32_t, int32_t, array_t)> configure;
    std::function<void()> close;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  xdg_toplevel_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  xdg_toplevel_t();
  explicit xdg_toplevel_t(const proxy_t &proxy);
  xdg_toplevel_t(xdg_toplevel *p, wrapper_type t = wrapper_type::standard);

  xdg_toplevel_t proxy_create_wrapper();

  static const std::string interface_name;

  operator xdg_toplevel*() const;

  /** \brief set the parent of this surface
      \param parent 

	Set the "parent" of this surface. This surface should be stacked
	above the parent surface and all other ancestor surfaces.

	Parent windows should be set on dialogs, toolboxes, or other
	"auxiliary" surfaces, so that the parent is raised when the dialog
	is raised.

	Setting a null parent for a child window removes any parent-child
	relationship for the child. Setting a null parent for a window which
	currently has no parent is a no-op.

	If the parent is unmapped then its children are managed as
	though the parent of the now-unmapped parent has become the
	parent of this surface. If no parent exists for the now-unmapped
	parent then the children are managed as though they have no
	parent surface.
      
  */
  void set_parent(xdg_toplevel_t parent);

  /** \brief Minimum protocol version required for the \ref set_parent function
  */
  static constexpr std::uint32_t set_parent_since_version = 1;

  /** \brief set surface title
      \param title 

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

  /** \brief set application ID
      \param app_id 

	Set an application identifier for the surface.

	The app ID identifies the general class of applications to which
	the surface belongs. The compositor can use this to group multiple
	surfaces together, or to determine how to launch a new application.

	For D-Bus activatable applications, the app ID is used as the D-Bus
	service name.

	The compositor shell will try to group application surfaces together
	by their app ID. As a best practice, it is suggested to select app
	ID's that match the basename of the application's .desktop file.
	For example, "org.freedesktop.FooViewer" where the .desktop file is
	"org.freedesktop.FooViewer.desktop".

	See the desktop-entry specification [0] for more details on
	application identifiers and how they relate to well-known D-Bus
	names and .desktop files.

	[0] http://standards.freedesktop.org/desktop-entry-spec/
      
  */
  void set_app_id(std::string app_id);

  /** \brief Minimum protocol version required for the \ref set_app_id function
  */
  static constexpr std::uint32_t set_app_id_since_version = 1;

  /** \brief show the window menu
      \param seat the wl_seat of the user event
      \param serial the serial of the user event
      \param x the x position to pop up the window menu at
      \param y the y position to pop up the window menu at

	Clients implementing client-side decorations might want to show
	a context menu when right-clicking on the decorations, giving the
	user a menu that they can use to maximize or minimize the window.

	This request asks the compositor to pop up such a window menu at
	the given position, relative to the local surface coordinates of
	the parent surface. There are no guarantees as to what menu items
	the window menu contains.

	This request must be used in response to some sort of user action
	like a button press, key press, or touch down event.
      
  */
  void show_window_menu(seat_t seat, uint32_t serial, int32_t x, int32_t y);

  /** \brief Minimum protocol version required for the \ref show_window_menu function
  */
  static constexpr std::uint32_t show_window_menu_since_version = 1;

  /** \brief start an interactive move
      \param seat the wl_seat of the user event
      \param serial the serial of the user event

	Start an interactive, user-driven move of the surface.

	This request must be used in response to some sort of user action
	like a button press, key press, or touch down event. The passed
	serial is used to determine the type of interactive move (touch,
	pointer, etc).

	The server may ignore move requests depending on the state of
	the surface (e.g. fullscreen or maximized), or if the passed serial
	is no longer valid.

	If triggered, the surface will lose the focus of the device
	(wl_pointer, wl_touch, etc) used for the move. It is up to the
	compositor to visually indicate that the move is taking place, such as
	updating a pointer cursor, during the move. There is no guarantee
	that the device focus will return when the move is completed.
      
  */
  void move(seat_t seat, uint32_t serial);

  /** \brief Minimum protocol version required for the \ref move function
  */
  static constexpr std::uint32_t move_since_version = 1;

  /** \brief start an interactive resize
      \param seat the wl_seat of the user event
      \param serial the serial of the user event
      \param edges which edge or corner is being dragged

	Start a user-driven, interactive resize of the surface.

	This request must be used in response to some sort of user action
	like a button press, key press, or touch down event. The passed
	serial is used to determine the type of interactive resize (touch,
	pointer, etc).

	The server may ignore resize requests depending on the state of
	the surface (e.g. fullscreen or maximized).

	If triggered, the client will receive configure events with the
	"resize" state enum value and the expected sizes. See the "resize"
	enum value for more details about what is required. The client
	must also acknowledge configure events using "ack_configure". After
	the resize is completed, the client will receive another "configure"
	event without the resize state.

	If triggered, the surface also will lose the focus of the device
	(wl_pointer, wl_touch, etc) used for the resize. It is up to the
	compositor to visually indicate that the resize is taking place,
	such as updating a pointer cursor, during the resize. There is no
	guarantee that the device focus will return when the resize is
	completed.

	The edges parameter specifies how the surface should be resized,
	and is one of the values of the resize_edge enum. The compositor
	may use this information to update the surface position for
	example when dragging the top left corner. The compositor may also
	use this information to adapt its behavior, e.g. choose an
	appropriate cursor image.
      
  */
  void resize(seat_t seat, uint32_t serial, xdg_toplevel_resize_edge edges);

  /** \brief Minimum protocol version required for the \ref resize function
  */
  static constexpr std::uint32_t resize_since_version = 1;

  /** \brief set the maximum size
      \param width 
      \param height 

	Set a maximum size for the window.

	The client can specify a maximum size so that the compositor does
	not try to configure the window beyond this size.

	The width and height arguments are in window geometry coordinates.
	See xdg_surface.set_window_geometry.

	Values set in this way are double-buffered. They will get applied
	on the next commit.

	The compositor can use this information to allow or disallow
	different states like maximize or fullscreen and draw accurate
	animations.

	Similarly, a tiling window manager may use this information to
	place and resize client windows in a more effective way.

	The client should not rely on the compositor to obey the maximum
	size. The compositor may decide to ignore the values set by the
	client and request a larger size.

	If never set, or a value of zero in the request, means that the
	client has no expected maximum size in the given dimension.
	As a result, a client wishing to reset the maximum size
	to an unspecified state can use zero for width and height in the
	request.

	Requesting a maximum size to be smaller than the minimum size of
	a surface is illegal and will result in a protocol error.

	The width and height must be greater than or equal to zero. Using
	strictly negative values for width and height will result in a
	protocol error.
      
  */
  void set_max_size(int32_t width, int32_t height);

  /** \brief Minimum protocol version required for the \ref set_max_size function
  */
  static constexpr std::uint32_t set_max_size_since_version = 1;

  /** \brief set the minimum size
      \param width 
      \param height 

	Set a minimum size for the window.

	The client can specify a minimum size so that the compositor does
	not try to configure the window below this size.

	The width and height arguments are in window geometry coordinates.
	See xdg_surface.set_window_geometry.

	Values set in this way are double-buffered. They will get applied
	on the next commit.

	The compositor can use this information to allow or disallow
	different states like maximize or fullscreen and draw accurate
	animations.

	Similarly, a tiling window manager may use this information to
	place and resize client windows in a more effective way.

	The client should not rely on the compositor to obey the minimum
	size. The compositor may decide to ignore the values set by the
	client and request a smaller size.

	If never set, or a value of zero in the request, means that the
	client has no expected minimum size in the given dimension.
	As a result, a client wishing to reset the minimum size
	to an unspecified state can use zero for width and height in the
	request.

	Requesting a minimum size to be larger than the maximum size of
	a surface is illegal and will result in a protocol error.

	The width and height must be greater than or equal to zero. Using
	strictly negative values for width and height will result in a
	protocol error.
      
  */
  void set_min_size(int32_t width, int32_t height);

  /** \brief Minimum protocol version required for the \ref set_min_size function
  */
  static constexpr std::uint32_t set_min_size_since_version = 1;

  /** \brief maximize the window

	Maximize the surface.

	After requesting that the surface should be maximized, the compositor
	will respond by emitting a configure event. Whether this configure
	actually sets the window maximized is subject to compositor policies.
	The client must then update its content, drawing in the configured
	state. The client must also acknowledge the configure when committing
	the new content (see ack_configure).

	It is up to the compositor to decide how and where to maximize the
	surface, for example which output and what region of the screen should
	be used.

	If the surface was already maximized, the compositor will still emit
	a configure event with the "maximized" state.

	If the surface is in a fullscreen state, this request has no direct
	effect. It may alter the state the surface is returned to when
	unmaximized unless overridden by the compositor.
      
  */
  void set_maximized();

  /** \brief Minimum protocol version required for the \ref set_maximized function
  */
  static constexpr std::uint32_t set_maximized_since_version = 1;

  /** \brief unmaximize the window

	Unmaximize the surface.

	After requesting that the surface should be unmaximized, the compositor
	will respond by emitting a configure event. Whether this actually
	un-maximizes the window is subject to compositor policies.
	If available and applicable, the compositor will include the window
	geometry dimensions the window had prior to being maximized in the
	configure event. The client must then update its content, drawing it in
	the configured state. The client must also acknowledge the configure
	when committing the new content (see ack_configure).

	It is up to the compositor to position the surface after it was
	unmaximized; usually the position the surface had before maximizing, if
	applicable.

	If the surface was already not maximized, the compositor will still
	emit a configure event without the "maximized" state.

	If the surface is in a fullscreen state, this request has no direct
	effect. It may alter the state the surface is returned to when
	unmaximized unless overridden by the compositor.
      
  */
  void unset_maximized();

  /** \brief Minimum protocol version required for the \ref unset_maximized function
  */
  static constexpr std::uint32_t unset_maximized_since_version = 1;

  /** \brief set the window as fullscreen on an output
      \param output 

	Make the surface fullscreen.

	After requesting that the surface should be fullscreened, the
	compositor will respond by emitting a configure event. Whether the
	client is actually put into a fullscreen state is subject to compositor
	policies. The client must also acknowledge the configure when
	committing the new content (see ack_configure).

	The output passed by the request indicates the client's preference as
	to which display it should be set fullscreen on. If this value is NULL,
	it's up to the compositor to choose which display will be used to map
	this surface.

	If the surface doesn't cover the whole output, the compositor will
	position the surface in the center of the output and compensate with
	with border fill covering the rest of the output. The content of the
	border fill is undefined, but should be assumed to be in some way that
	attempts to blend into the surrounding area (e.g. solid black).

	If the fullscreened surface is not opaque, the compositor must make
	sure that other screen content not part of the same surface tree (made
	up of subsurfaces, popups or similarly coupled surfaces) are not
	visible below the fullscreened surface.
      
  */
  void set_fullscreen(output_t output);

  /** \brief Minimum protocol version required for the \ref set_fullscreen function
  */
  static constexpr std::uint32_t set_fullscreen_since_version = 1;

  /** \brief unset the window as fullscreen

	Make the surface no longer fullscreen.

	After requesting that the surface should be unfullscreened, the
	compositor will respond by emitting a configure event.
	Whether this actually removes the fullscreen state of the client is
	subject to compositor policies.

	Making a surface unfullscreen sets states for the surface based on the following:
	* the state(s) it may have had before becoming fullscreen
	* any state(s) decided by the compositor
	* any state(s) requested by the client while the surface was fullscreen

	The compositor may include the previous window geometry dimensions in
	the configure event, if applicable.

	The client must also acknowledge the configure when committing the new
	content (see ack_configure).
      
  */
  void unset_fullscreen();

  /** \brief Minimum protocol version required for the \ref unset_fullscreen function
  */
  static constexpr std::uint32_t unset_fullscreen_since_version = 1;

  /** \brief set the window as minimized

	Request that the compositor minimize your surface. There is no
	way to know if the surface is currently minimized, nor is there
	any way to unset minimization on this surface.

	If you are looking to throttle redrawing when minimized, please
	instead use the wl_surface.frame event for this, as this will
	also work with live previews on windows in Alt-Tab, Expose or
	similar compositor features.
      
  */
  void set_minimized();

  /** \brief Minimum protocol version required for the \ref set_minimized function
  */
  static constexpr std::uint32_t set_minimized_since_version = 1;

  /** \brief suggest a surface change
      \param width 
      \param height 
      \param states 

	This configure event asks the client to resize its toplevel surface or
	to change its state. The configured state should not be applied
	immediately. See xdg_surface.configure for details.

	The width and height arguments specify a hint to the window
	about how its surface should be resized in window geometry
	coordinates. See set_window_geometry.

	If the width or height arguments are zero, it means the client
	should decide its own window dimension. This may happen when the
	compositor needs to configure the state of the surface but doesn't
	have any information about any previous or expected dimension.

	The states listed in the event specify how the width/height
	arguments should be interpreted, and possibly how it should be
	drawn.

	Clients must send an ack_configure in response to this event. See
	xdg_surface.configure and xdg_surface.ack_configure for details.
      
  */
  std::function<void(int32_t, int32_t, array_t)> &on_configure();

  /** \brief surface wants to be closed

	The close event is sent by the compositor when the user
	wants the surface to be closed. This should be equivalent to
	the user clicking the close button in client-side decorations,
	if your application has any.

	This is only a request that the user intends to close the
	window. The client may choose to ignore this request, or show
	a dialog to ask the user to save their data, etc.
      
  */
  std::function<void()> &on_close();

};

/** \brief edge values for resizing

	These values are used to indicate which edge of a surface
	is being dragged in a resize operation.
      
  */
struct xdg_toplevel_resize_edge : public detail::bitfield<4, 10>
{
  xdg_toplevel_resize_edge(const detail::bitfield<4, 10> &b)
    : detail::bitfield<4, 10>(b) {}
  xdg_toplevel_resize_edge(const uint32_t value)
    : detail::bitfield<4, 10>(value) {}
  static const detail::bitfield<4, 10> none;
  static const detail::bitfield<4, 10> top;
  static const detail::bitfield<4, 10> bottom;
  static const detail::bitfield<4, 10> left;
  static const detail::bitfield<4, 10> top_left;
  static const detail::bitfield<4, 10> bottom_left;
  static const detail::bitfield<4, 10> right;
  static const detail::bitfield<4, 10> top_right;
  static const detail::bitfield<4, 10> bottom_right;
};

/** \brief types of state on the surface

	The different state values used on the surface. This is designed for
	state values like maximized, fullscreen. It is paired with the
	configure event to ensure that both the client and the compositor
	setting the state can be synchronized.

	States set in this way are double-buffered. They will get applied on
	the next commit.
      
  */
enum class xdg_toplevel_state : uint32_t
  {
  /** \brief the surface is maximized */
  maximized = 1,
  /** \brief the surface is fullscreen */
  fullscreen = 2,
  /** \brief the surface is being resized */
  resizing = 3,
  /** \brief the surface is now activated */
  activated = 4,
  tiled_left = 5,
  tiled_right = 6,
  tiled_top = 7,
  tiled_bottom = 8
};


/** \brief short-lived, popup surfaces for menus

      A popup surface is a short-lived, temporary surface. It can be used to
      implement for example menus, popovers, tooltips and other similar user
      interface concepts.

      A popup can be made to take an explicit grab. See xdg_popup.grab for
      details.

      When the popup is dismissed, a popup_done event will be sent out, and at
      the same time the surface will be unmapped. See the xdg_popup.popup_done
      event for details.

      Explicitly destroying the xdg_popup object will also dismiss the popup and
      unmap the surface. Clients that want to dismiss the popup when another
      surface of their own is clicked should dismiss the popup using the destroy
      request.

      A newly created xdg_popup will be stacked on top of all previously created
      xdg_popup surfaces associated with the same xdg_toplevel.

      The parent of an xdg_popup must be mapped (see the xdg_surface
      description) before the xdg_popup itself.

      The x and y arguments passed when creating the popup object specify
      where the top left of the popup should be placed, relative to the
      local surface coordinates of the parent surface. See
      xdg_surface.get_popup. An xdg_popup must intersect with or be at least
      partially adjacent to its parent surface.

      The client must call wl_surface.commit on the corresponding wl_surface
      for the xdg_popup state to take effect.
    
*/
class xdg_popup_t : public proxy_t
{
private:
  struct events_t : public detail::events_base_t
  {
    std::function<void(int32_t, int32_t, int32_t, int32_t)> configure;
    std::function<void()> popup_done;
  };

  static int dispatcher(uint32_t opcode, std::vector<detail::any> args, std::shared_ptr<detail::events_base_t> e);

  xdg_popup_t(proxy_t const &wrapped_proxy, construct_proxy_wrapper_tag);

public:
  xdg_popup_t();
  explicit xdg_popup_t(const proxy_t &proxy);
  xdg_popup_t(xdg_popup *p, wrapper_type t = wrapper_type::standard);

  xdg_popup_t proxy_create_wrapper();

  static const std::string interface_name;

  operator xdg_popup*() const;

  /** \brief make the popup take an explicit grab
      \param seat the wl_seat of the user event
      \param serial the serial of the user event

	This request makes the created popup take an explicit grab. An explicit
	grab will be dismissed when the user dismisses the popup, or when the
	client destroys the xdg_popup. This can be done by the user clicking
	outside the surface, using the keyboard, or even locking the screen
	through closing the lid or a timeout.

	If the compositor denies the grab, the popup will be immediately
	dismissed.

	This request must be used in response to some sort of user action like a
	button press, key press, or touch down event. The serial number of the
	event should be passed as 'serial'.

	The parent of a grabbing popup must either be an xdg_toplevel surface or
	another xdg_popup with an explicit grab. If the parent is another
	xdg_popup it means that the popups are nested, with this popup now being
	the topmost popup.

	Nested popups must be destroyed in the reverse order they were created
	in, e.g. the only popup you are allowed to destroy at all times is the
	topmost one.

	When compositors choose to dismiss a popup, they may dismiss every
	nested grabbing popup as well. When a compositor dismisses popups, it
	will follow the same dismissing order as required from the client.

	The parent of a grabbing popup must either be another xdg_popup with an
	active explicit grab, or an xdg_popup or xdg_toplevel, if there are no
	explicit grabs already taken.

	If the topmost grabbing popup is destroyed, the grab will be returned to
	the parent of the popup, if that parent previously had an explicit grab.

	If the parent is a grabbing popup which has already been dismissed, this
	popup will be immediately dismissed. If the parent is a popup that did
	not take an explicit grab, an error will be raised.

	During a popup grab, the client owning the grab will receive pointer
	and touch events for all their surfaces as normal (similar to an
	"owner-events" grab in X11 parlance), while the top most grabbing popup
	will always have keyboard focus.
      
  */
  void grab(seat_t seat, uint32_t serial);

  /** \brief Minimum protocol version required for the \ref grab function
  */
  static constexpr std::uint32_t grab_since_version = 1;

  /** \brief configure the popup surface
      \param x x position relative to parent surface window geometry
      \param y y position relative to parent surface window geometry
      \param width window geometry width
      \param height window geometry height

	This event asks the popup surface to configure itself given the
	configuration. The configured state should not be applied immediately.
	See xdg_surface.configure for details.

	The x and y arguments represent the position the popup was placed at
	given the xdg_positioner rule, relative to the upper left corner of the
	window geometry of the parent surface.
      
  */
  std::function<void(int32_t, int32_t, int32_t, int32_t)> &on_configure();

  /** \brief popup interaction is done

	The popup_done event is sent out when a popup is dismissed by the
	compositor. The client should destroy the xdg_popup object at this
	point.
      
  */
  std::function<void()> &on_popup_done();

};

/** \brief 

  */
enum class xdg_popup_error : uint32_t
  {
  /** \brief tried to grab after being mapped */
  invalid_grab = 0
};



}
