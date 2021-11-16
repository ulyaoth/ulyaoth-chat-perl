#!/usr/bin/perl -w
 

print "Content-type: text/html\n\n";

 foreach (keys %ENV) { print "$_ = $ENV{$_}<br>\n"; };
 exit();
