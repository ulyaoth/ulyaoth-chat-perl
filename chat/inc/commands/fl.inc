#!/usr/bin/perl

print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";

require "$root/inc/print_room.inc";

print "<hr color=\"#3300FF\">\n*** Private message buffer being flushed.<br>\n</body>\n";

if($frames ne 'yes'){

require "$root/inc/print_footer.inc";

}

unlink ("$root/online/pm/$DATA{'n'}.txt");

exit;



        