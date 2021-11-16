#!/usr/bin/perl

print <<"(END HTML FOOTER)";

<html>
<head>
<title>$title  - Control Panel</title>
</head>
<frameset rows="100%" cols="145,*" frameborder=0 border=0 framespacing=0>
<frame name="side" src="cp.cgi?ops=$DATA{'ops'}&s=$id&a=side" scrolling="Auto" marginheight=1 marginwidth=10 noresize>
<frame name="main" src="cp.cgi?ops=$DATA{'ops'}&s=$id&a=main" marginheight=1 marginwidth=10>
</frameset>
<noframes>

<b>You need a browser that supports frames!</b>
</noframes>
</html>

(END HTML FOOTER)

return true;
