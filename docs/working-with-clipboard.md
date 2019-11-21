---
apple-itunes-app: 'app-id=828256236,app-argument=medium://p/b4564b906d46'
author: George Shuklin
description: |
    My goal is to copy PNG image into a clipboard. When I decided that this
    is a good feature to have in my app, I thought about it as a small
    two/three-liner with a help of some small library. Turned...
lang: en
parsely-post-id: b4564b906d46
referrer: 'unsafe-url'
robots: 'index,follow'
theme-color: '\#000000'
title:
- 'Working with clipboard - journey to rust - Medium'
- 'Working with clipboard - journey to rust - Medium'
twitter:app:id:iphone: 828256236
twitter:app:name:iphone: Medium
twitter:app:url:iphone: 'medium://p/b4564b906d46'
twitter:card: 'summary\_large\_image'
twitter:image:src: 'https://miro.medium.com/max/340/1\*5gWX7vaASLwvTwAv79UsIg.png'
twitter:site: '\@Medium'
viewport: 'width=device-width,minimum-scale=1,initial-scale=1'
---

::: {#root}
::: {.a .b .c}
::: {.d .e .f .g .h .i .j .k}
:::

::: {.branch-journeys-top}
::: {.l .c}
::: {.section .v .w .x .y .z .ab .ac .ae .af .ag .ah .ai}
::: {.af .ag .aj .q}
::: {.ak .l}
:::

::: {.am .an .ao .ap .aq .l .g}
:::

::: {.l .g}
[[journey to rust]{.ar .as .at .au .av .aw .ax .ay .az .ba
.bb}](/journey-to-rust?source=post_page-----b4564b906d46----------------------)
:::
:::

::: {.l .bc .q}
::: {.af .ag}
::: {.af .g}
::: {.bd .l}
[[Sign
in](https://medium.com/m/signin?operation=login&redirect=https%3A%2F%2Fmedium.com%2Fjourney-to-rust%2Fworking-with-clipboard-b4564b906d46&source=post_page-----b4564b906d46---------------------nav_reg-){.bk
.bl .bm .bn .bo .bp .bq .br .bs .bt .bu .bv .bw .bx .by .bz}]{.ar .b .be
.bf .bg .bh .l .bi .bj}
:::
:::

::: {.bd .l}
Get started
:::
:::
:::
:::
:::

::: {.cj .ck .c .cl}
::: {.section .v .w .x .y .cm .ab .ac .ae .av .af .ag}
::: {.cn .l .bc}
[[journey to rust]{.ar .as .co .cp .av .cq .ax .ay .az .ba
.cr}](/journey-to-rust?source=post_page-----b4564b906d46----------------------)
:::

::: {.cs .l .ct}
:::
:::
:::
:::

::: {.dc .z .l .dd .de}
:::

::: {.section .v .w .x .y .ab .df .ae .af .dg}
:::

[]{.l}

<div>

::: {.gj .o .jb .jc .jd .di}
:::

::: {.section .je .jf .jg .jh .ji}
::: {.ae .jj .ab .df .v .w}
<div>

::: {#dc5a .jk .jl .cr .be .jm .b .jn .jo .jp .jq .jr .js .jt}
Working with clipboard {#working-with-clipboard .jm .b .jn .ju .cr}
======================
:::

</div>

::: {#1ff4 .jv .jl .bi .be .ar .ea .jw .jx .jy .jz .ka .kb .kc}
X11, aren't you dead yet? {#x11-arent-you-dead-yet .ar .ea .kd .ke .bi}
-------------------------
:::

::: {.kf}
::: {.ag .af}
<div>

[![George
Shuklin](https://miro.medium.com/fit/c/96/96/1*sDbMJ28pBc0x9epC6OAOKw.jpeg){.l
.fq .kg .kh width="48"
height="48"}](/@george.shuklin?source=post_page-----b4564b906d46----------------------)

</div>

::: {.ki .ab .l}
::: {.af}
::: {style="flex:1"}
[]{.ar .b .be .bf .bg .bh .l .cr .al}

::: {.kj .af .ag .kk}
[[George
Shuklin](/@george.shuklin?source=post_page-----b4564b906d46----------------------){.dr
.ds .bm .bn .bo .bp .bq .br .bs .bt .ja .bw .bx .dv .dw}]{.ar .ea .eb
.bf .av .kl .ax .ay .az .ba .cr}

::: {.km .l .bc .h}
Follow
:::
:::
:::
:::

[[]{.ar .ea .eb .bf .av .kl .ax .ay .az .ba .bi}]{.ar .b .be .bf .bg .bh
.l .bi .bj}

<div>

[May
22](/journey-to-rust/working-with-clipboard-b4564b906d46?source=post_page-----b4564b906d46----------------------){.dr
.ds .bm .bn .bo .bp .bq .br .bs .bt .ja .bw .bx .dv .dw} · 5 min read

</div>
:::
:::
:::

My goal is to copy PNG image into a clipboard. When I decided that this
is a good feature to have in my app, I thought about it as a small
two/three-liner with a help of some small library.

Turned out, CLIPBOARD is a COMPLICATED in X11 and THERE ARE DEEP
HISTORICAL REASONS for it TO BE PAIN IN THE ASS. Sorry for all-caps,
there are deep historical reasons for it.

This post have more to X11 than to Rust, but I try to work with it in
Rust, so, it's Rust domain too.

X11 clipboard 101 {#63a2 .ln .lo .cr .be .ar .as .lp .lq .lr .ls .lt .lu .lv .lw .lx .ly .lz}
=================

1.  [This 'thing' is called "selection". Every time I use 'selection' it
    translates into 'clipboard' for all other systems. There are few
    selections, PRIMARY (middle button paste) and CLIPBOARD. Yes, there
    is a selection called CLIPBOARD, handling Ctrl-C/V operations. For
    normal human this means there is a clipboard called CLIPBOARD. Not
    to be mistaken with PRIMARY, SECONDARY or cut buffers.]{#a4f3}
2.  [Selection acts as RPC through X11. Sender (Ctrl-C) posses (starts
    to own) the CLIPBOARD selection. \[*Owning for clipboard in X11 is
    completely different from ownership on the Rust, one can just go and
    grab it... Sounds more like a robbery to me*\]. Receiver (Ctrl-V)
    negotiates TARGETS (available formats) for transfer with Sender.
    Sender transfer one of the negotiated formats in chunks of about
    256k. I omitted exact details of interactions (as I don't know them
    yet by myself).]{#4d30}
3.  [There is a special standard ICCCM, which does not cover all actual
    usage of the clipboard. That means some of the stuff from standard
    is no longer true, and some stuff happening in the system is not
    covered by standard (f.e. UTF-8). One more reason to bury X11
    ASAP.]{#d98d}

My primal guideline is this article:
<https://www.uninformativ.de/blog/postings/2017-04-02/0/POSTING-en.html>

Libraries rummage {#4fd8 .ln .lo .cr .be .ar .as .lp .lq .lr .ls .lt .lu .lv .lw .lx .ly .lz}
=================

I'll start from
[https://crates.io/crates/clipboard,](https://crates.io/crates/clipboard){.dr
.ci .mo .mp .mq .mr} it looks as pretty high-level (given the gory
details in the post above). Unfortunately, given this
[issue](https://github.com/aweinstock314/rust-clipboard/issues/46){.dr
.ci .mo .mp .mq .mr} (no binary support for clipboard), my PNG copypaste
can't proceed with it.

Next thing is in those gory details...
<https://crates.io/crates/x11-clipboard>

Because it's gory, I will follow the post and try to implement those
things one by one..

Documentation is scarce and there is only one example. It compiles and
works. Ironically, at first run it have own source code in the clipboard
due to obvious reasons.

In source code of the library I see this:

``` {.ms .mt .mu .mv .mw .hg .fj .cx}
pub struct Atoms {                           
  pub primary: Atom,                           
  pub clipboard: Atom,                           
  pub property: Atom,                           
  pub targets: Atom,                           
  pub string: Atom,                           
  pub utf8_string: Atom,                           
  pub incr: Atom                       
}
```

I may be utterly wrong, but that means, no images. Please, correct me.

The [xcb](https://crates.io/crates/xcb){.dr .ci .mo .mp .mq .mr}
bindings I consider the worst possible finale.

My next attempt looks hilarious. So hilarious that it may just works:
<https://github.com/dmac/clipboard/blob/master/src/clipboard_linux.rs>

Yes, it just calls an external xclip binary and uses a less intimidating
stdin/out protocol. Unfortunately, there is no updates (5 years!) there
is a complain for old Rust in issues and I can't find it on crates.io.

What a sad story. But I got the idea. No gory details. Nasty, but the
only option within my reach. It sounds like 'write your own'. Fallback
option number one. (Number two is to 'save into file', which is
possible, but undesirable).

Shall I submit myself into gtk camp?

Uuh. What a dependency mess. Even my PC is heavily build-oriented
(thanks to freecad mess), I got a pack of external dependencies for apt:

-   [libpango1.0-dev]{#c60b}
-   [libcairo2-dev]{#7a69}
-   [libatk1.0-dev]{#c53b}
-   [libgdk-pixbuf2.0-dev]{#fd4c}
-   [libgtk-3-dev]{#114c}

Some help to those who affected: when you have this type of error:

``` {.ms .mt .mu .mv .mw .hg .fj .cx}
Compiling gobject-sys v0.8.0
   Compiling cairo-sys-rs v0.8.0
error: failed to run custom build command for `atk-sys v0.8.0`
process didn't exit successfully: `/home/amarao/prg/rust/clip-test/target/debug/build/atk-sys-1ce77b66bbe979e1/build-script-build` (exit code: 1)
--- stderr
`"pkg-config" "--libs" "--cflags" "atk >= 2.14"` did not exit successfully: exit code: 1
--- stderr
Package atk was not found in the pkg-config search path.
Perhaps you should add the directory containing `atk.pc'
to the PKG_CONFIG_PATH environment variable
No package 'atk' foundwarning: build failed, waiting for other jobs to finish..
```

(debian/ubuntu) there is an easy way to find a missing package:

``` {.ms .mt .mu .mv .mw .hg .fj .cx}
apt-file search atk.pc
libatk1.0-dev: /usr/lib/x86_64-linux-gnu/pkgconfig/atk.pc
sudo apt install libatk1.0-dev
```

After some terrible compilation. (2.2Gb of memory, 400% CPU for about
two minutes) I got my app:

![243k binary requires more than 2Gb of memory to
compile](https://miro.medium.com/max/60/1*5gWX7vaASLwvTwAv79UsIg.png?q=20){.gj
.n .o .gi .ab .np .nq .nr width="340" height="242"}

Well, at least it works. Next is how to do clipboard with GTK?

GTK and selections {#0d52 .ln .lo .cr .be .ar .as .lp .lq .lr .ls .lt .lu .lv .lw .lx .ly .lz}
==================

Confession: I use gtk applications a lot, and I have no idea how to
write gtk applications. So, I feel it's gonna a really complicated
topic. I'll focus only on clipboard thing for now.

I jumping through monstrous library, hoping to grasp enough to do the
job. Insofar I found:

``` {.ms .mt .mu .mv .mw .hg .fj .cx}
let mut clipboard = gtk::Clipboard::get(...
```

Which requires gdk::Atom, but when I use `gtk::gdk::Atom`{.nn .nw .nx
.ny .my .b}, Rust complains that this is a private crate.

Oh, I found this:
<http://gtk-rs.org/docs/gdk/constant.SELECTION_CLIPBOARD.html>

I can't use it, it's private.

There is a use `gtk::gdk::prelude::*`{.nn .nw .nx .ny .my .b}, but it
contains no SELECTION\_CLIPBOARD. Euh...

I found some project using GTK and Rust. I see...
<https://gitlab.gnome.org/danigm/fractal/blob/master/fractal-gtk/src/widgets/message_menu.rs#L192>

``` {.ms .mt .mu .mv .mw .hg .fj .cx}
let atom = gdk::Atom::intern("CLIPBOARD");
let clipboard = gtk::Clipboard::get(&atom);
```

I've tried this. How they got access to `gdk`{.nn .nw .nx .ny .my .b}?
Just extern crate gdk? But I don't have it... Should I?

Yes, they have it as an external dependency in
[Cargo.toml](https://gitlab.gnome.org/danigm/fractal/blob/master/fractal-gtk/Cargo.toml){.dr
.ci .mo .mp .mq .mr}.

I'll do the same. `gdk = “0.10.0”`{.nn .nw .nx .ny .my .b} into
`Cargo.toml`{.nn .nw .nx .ny .my .b} and my code compiles.

Now, I need to send image. There is a juicy function I begged for:

> `pub fn set_image(&self, pixbuf: &Pixbuf)`{.nn .nw .nx .ny .my .b}
>
> Sets the contents of the clipboard to the given
> `gdk_pixbuf::Pixbuf`{.nn .nw .nx .ny .my .b}. GTK+ will take
> responsibility for responding for requests for the image, and for
> converting the image into the requested format.

All I have to do is to create pixbuf. `gdk_pixbuf::Pixbuf`{.nn .nw .nx
.ny .my .b} to be precise. A new crate?
[Yep](https://crates.io/crates/gdk-pixbuf){.dr .ci .mo .mp .mq .mr}.

Huh, more tinkering, and I got my code running. Immediately there was a
warning: "gdk\_pixbuf\_calculate\_rowstride: assertion
'bits\_per\_sample == 8' failed".

Yep, it was 32. I thought it's per pixel. No, it's per channel. So it
should be 8.

``` {.ms .mt .mu .mv .mw .hg .fj .cx}
extern crate gdk;
extern crate gdk_pixbuf;
extern crate gtk;
...
        let atom = gdk::Atom::intern("CLIPBOARD");
        let clipboard = gtk::Clipboard::get(&atom);
        let mut pixbuf = gdk_pixbuf::Pixbuf::new(
            gdk_pixbuf::Colorspace::Rgb,
            false,
            8,
            42,
            42
        ).unwrap();
```

Next goal: put something into buffer.

There is a fill function. And it takes `&self`{.nn .nw .nx .ny .my .b},
but fill it with color. WTF? Why not `&mut self`{.nn .nw .nx .ny .my
.b}? Yes, yes, there is an
[unsafe](http://gtk-rs.org/docs/src/gdk_pixbuf/auto/pixbuf.rs.html#538){.dr
.ci .mo .mp .mq .mr}, but why? Looks like bug to me.

Fill looks simple:

``` {.ms .mt .mu .mv .mw .hg .fj .cx}
pixbuf.fill(0x90101000);
```

And send it:

![Oops, someone set clipboard to this.
Happy!](https://miro.medium.com/max/60/1*SYB4YdSOYa0PU-XWqZ3ODg.png?q=20){.gj
.n .o .gi .ab .np .nq .nr width="42" height="42"}

Anyway, this send image to clipboard:

``` {.ms .mt .mu .mv .mw .hg .fj .cx}
clipboard.set_image(&pixbuf);
```

Can I use clipboard without main event loop? No.

``` {.ms .mt .mu .mv .mw .hg .fj .cx}
thread 'main' panicked at 'GDK has not been initialized. Call `gdk::init` or `gtk::init` first.', /home/amarao/.cargo/registry/src/github.com-1ecc6299db9ec823/gdk-0.10.0/src/atom.rs:35:9
note: Run with `RUST_BACKTRACE=1` for a backtrace.
```

I can call gtk::init(), but without event loop everything freezes in
Ctrl-V operation in gimp, even if I add `loop{}`{.nn .nw .nx .ny .my .b}
at the end of application.

It looks like I need to switch from minifb to gtk for visualization, as
two event loops is too much for a small application to handle.

Upd: final source code is here:
<https://github.com/amarao/rust_gtk_clipboard_image_paste>
:::
:::

</div>

::: {.dh .di .dj .m .dk .dl .dm .dn .do .e test-id="post-sidebar"}
::: {.af .dg}
::: {.dp .dq .l}
[](/journey-to-rust?source=post_sidebar--------------------------post_sidebar-){.dr
.ds .bm .bn .bo .bp .bq .br .bs .bt .dt .du .bw .bx .dv .dw}

journey to rust {#journey-to-rust .ar .as .dx .bf .cr}
---------------

::: {.dy .dz .l}
#### Side notes on learning Rust language {#side-notes-on-learning-rust-language .ar .ea .eb .bf .av .ec .ax .ay .ed .ba .bi}
:::

::: {.ch}
Follow
:::
:::

::: {.ef .eg .eh .af}
::: {.af .ag}
::: {.ei .l .ej}
[](https://medium.com/m/signin?operation=register&redirect=https%3A%2F%2Fmedium.com%2Fjourney-to-rust%2Fworking-with-clipboard-b4564b906d46&source=post_sidebar-----b4564b906d46---------------------clap_sidebar-){.dr
.ds .bm .bn .bo .bp .bq .br .bs .bt .dt .du .bw .bx .dv .dw}

::: {.br .ek .el .em .en .eo .ep .eq .bl .er .bv}
:::
:::

::: {.es .l}
::: {.et}
#### 1 {#section .ar .ea .eb .bf .bi}
:::
:::
:::
:::

<div>

::: {.ch}
:::

</div>
:::
:::

<div>

::: {.eu .ev .af .dg .ew}
::: {.af .ew}
::: {.ex .ey .ez .fa .fb .fc .ab}
::: {.af .fd}
:::

::: {.af .ag .fd}
:::

::: {.fe .l}
-   [Rust](/tag/rust){.fh .fi .ci .bi .l .fj .fk .a .b .fl}
-   [Gtk](/tag/gtk){.fh .fi .ci .bi .l .fj .fk .a .b .fl}
-   [X11](/tag/x11){.fh .fi .ci .bi .l .fj .fk .a .b .fl}
-   [Clipboard](/tag/clipboard){.fh .fi .ci .bi .l .fj .fk .a .b .fl}
-   [GUI](/tag/gui){.fh .fi .ci .bi .l .fj .fk .a .b .fl}
:::

::: {.fm .af .fn .u}
::: {.af .ag}
::: {.fo .l .ej}
[](https://medium.com/m/signin?operation=register&redirect=https%3A%2F%2Fmedium.com%2Fjourney-to-rust%2Fworking-with-clipboard-b4564b906d46&source=post_actions_footer-----b4564b906d46---------------------clap_footer-){.dr
.ds .bm .bn .bo .bp .bq .br .bs .bt .dt .du .bw .bx .dv .dw}

::: {.c .fp .fq .af .ag .fr .ej .fs .ft .fu .fv .fw .fx .fy .fz .ga .gb .gc .gd .ge .cd}
::: {.br .ek .el .em .en .eo .gf .eq .ag .gg .fq .af .ew .gh .o .gi .gj .n .ab .bl .er .bv .gk}
:::
:::
:::

::: {.es .l}
::: {.et}
#### 1 clap {#clap .ar .ea .eb .bf .cr}
:::
:::
:::

::: {.af .ag}
::: {.gl .l .bc .g}
:::

::: {.gl .l .bc .g}
:::

::: {.gl .ck .cl}
::: {.ch}
:::
:::

::: {.gl .l .bc}
<div>

::: {.ch}
:::

</div>
:::

::: {.ch}
::: {.ch}
::: {.l .bc}
:::
:::
:::
:::
:::

::: {.gm .cj .gn .fe .l .u}
::: {.go .gp .l .ej}
[]{.l .gq .ai .gr}

::: {.l .gj .gs .gt}
[![George
Shuklin](https://miro.medium.com/fit/c/160/160/1*sDbMJ28pBc0x9epC6OAOKw.jpeg){.l
.fq .db .gu width="80"
height="80"}](/@george.shuklin?source=follow_footer--------------------------follow_footer-)
:::

[]{.l}

::: {.gv .l .gw}
Written by
:::

::: {.gv .gz .af .gw}
::: {.ab .af .ag .fn}
[George Shuklin](/@george.shuklin?source=follow_footer--------------------------follow_footer-){.dr .ds .bm .bn .bo .bp .bq .br .bs .bt .dt .du .bw .bx .dv .dw} {#george-shuklin .ar .as .at .au .cr}
----------------------------------------------------------------------------------------------------------------------------------------------------------------

::: {.l .g}
Follow
:::
:::
:::

::: {.gv .ha .l .gw .cl}
::: {.hb .l}
#### I work at Servers.com, most of my stories are about Ansible, Ceph, Python, Openstack and Linux. {#i-work-at-servers.com-most-of-my-stories-are-about-ansible-ceph-python-openstack-and-linux. .ar .ea .dx .hc .bi}
:::

::: {.ck .hd .cl}
Follow
:::
:::
:::

::: {.gm .l}
:::

::: {.go .gp .l .ej}
[]{.l .gq .ai .gr}

::: {.l .gj .gs .gt}
[![journey to
rust](https://miro.medium.com/fit/c/160/160/1*Ag7TuS353F9JKOGU5tgLvA.jpeg){.ce
.gu .db width="80"
height="80"}](/journey-to-rust?source=follow_footer--------------------------follow_footer-)
:::

[]{.l}

::: {.gv .gz .af .gw}
::: {.ab .af .ag .fn}
[journey to rust](/journey-to-rust?source=follow_footer--------------------------follow_footer-){.dr .ds .bm .bn .bo .bp .bq .br .bs .bt .dt .du .bw .bx .dv .dw} {#journey-to-rust-1 .ar .as .at .au .cr}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------

::: {.l .g}
::: {.ch}
Follow
:::
:::
:::
:::

::: {.gv .he .l .gw .cl}
::: {.hb .l}
#### Side notes on learning Rust language {#side-notes-on-learning-rust-language-1 .ar .ea .dx .hc .bi}
:::

::: {.ck .hd .cl}
::: {.ch}
Follow
:::
:::
:::
:::
:::

::: {.hf .cj .l .u}
[](https://medium.com/p/b4564b906d46/responses/show?source=follow_footer--------------------------follow_footer-){.dr
.ds .bm .bn .bo .bp .bq .br .bs .bt .dt .du .bw .bx .dv .dw}

::: {.hg .hh .fh .l .hi .g}
[Write the first response]{.bk}
:::
:::
:::
:::

::: {.hj .l .hk .u}
::: {.af .ew}
::: {.ex .ey .ez .fa .fb .hl .ab}
:::
:::
:::
:::

</div>

::: {.hm .l .hn .ho}
::: {.section .x .y .ab .ae .l .hp .hq .hr .hs .ht .hu .hv .hw .hx .hy .hz .ia .ib .ic .id}
::: {.ie .if .go .af .fn .g}
::: {.ig .af .fn}
::: {.ih .l .ii}
::: {.ij .l}
[](https://medium.com/about?autoplay=1&source=post_page-----b4564b906d46----------------------){.dr
.ds .bm .bn .bo .bp .bq .br .bs .bt .ik .il .bw .bx .im .in}

#### Discover Medium {#discover-medium .io .ip .iq .ar .as .be .hc .ir .is .l}
:::

[Welcome to a place where words matter. On Medium, smart voices and
original ideas take center stage - with no ads in sight.
[Watch](https://medium.com/about?autoplay=1&source=post_page-----b4564b906d46----------------------){.dr
.ds .bm .bn .bo .bp .bq .br .bs .bt .bw .bx .im .in .iv}]{.ar .b .be .bf
.bg .bh .l .it .iu}
:::

::: {.ih .l .ii}
::: {.iw .l}
[](https://medium.com/topics?source=post_page-----b4564b906d46----------------------){.dr
.ds .bm .bn .bo .bp .bq .br .bs .bt .ik .il .bw .bx .im .in}

#### Make Medium yours {#make-medium-yours .io .ip .iq .ar .as .be .hc .ir .is .l}
:::

[Follow all the topics you care about, and we'll deliver the best
stories for you to your homepage and inbox.
[Explore](https://medium.com/topics?source=post_page-----b4564b906d46----------------------){.dr
.ds .bm .bn .bo .bp .bq .br .bs .bt .bw .bx .im .in .iv}]{.ar .b .be .bf
.bg .bh .l .it .iu}
:::

::: {.ih .l .ii}
::: {.ij .l}
[](https://medium.com/membership?source=post_page-----b4564b906d46----------------------){.dr
.ds .bm .bn .bo .bp .bq .br .bs .bt .ik .il .bw .bx .im .in}

#### Become a member {#become-a-member .io .ip .iq .ar .as .be .hc .ir .is .l}
:::

[Get unlimited access to the best stories on Medium --- and support
writers while you're at it. Just \$5/month.
[Upgrade](https://medium.com/membership?source=post_page-----b4564b906d46----------------------){.dr
.ds .bm .bn .bo .bp .bq .br .bs .bt .bw .bx .im .in .iv}]{.ar .b .be .bf
.bg .bh .l .it .iu}
:::
:::
:::

::: {.af .ag .fn}
[]{.ar .b .be .bf .bg .bh .l .it .iu}

::: {.ix .iy .af .fn .iz .ai}
[About](https://medium.com/about?autoplay=1&source=post_page-----b4564b906d46----------------------){.dr
.ds .bm .bn .bo .bp .bq .br .bs .bt .ja .bw .bx .im
.in}[Help](https://help.medium.com/?source=post_page-----b4564b906d46----------------------){.dr
.ds .bm .bn .bo .bp .bq .br .bs .bt .ja .bw .bx .im
.in}[Legal](/policy/9db0094a1e0f?source=post_page-----b4564b906d46----------------------){.dr
.ds .bm .bn .bo .bp .bq .br .bs .bt .ja .bw .bx .im .in}
:::
:::
:::
:::
:::
:::
