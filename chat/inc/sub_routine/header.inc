#!/usr/bin/perl

print $refresher;

print "<HEAD><title>$title</TITLE>\n";

print $style;

print $msgjava;

print $body;

print $method;

print "<font color=\"#3300FF\"><b>$title ($room) · <!--#exec cgi=\"r.cgi\"--> ·</b></font>\n<hr color=\"#3300FF\">\n";

return true;