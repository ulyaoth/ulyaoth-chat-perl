#!/usr/bin/perl



if ($frames ne "yes"){       



dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);



$USER{'frames'} = "yes";



dbmclose(%USER);



$frames = "yes";



print "Content-type: text/html\n\n";
#print "Pragma: nocache\n";
#print "Cache-Control: no-cache, must-revalidate, no-store\n\n";




print "<HTML>\n";



print "<HEAD><title>$title</TITLE></HEAD>\n";



print "<FRAMESET ROWS=\"*,90\">\n";



print "<FRAME SRC=\"$location?n=$DATA{'n'}&room=$DATA{'room'}&igfocus=1&id=$DATA{'id'}#b\" name=\"display\" MARGINWIDTH=\"0\" MARGINHEIGHT=\"0\" FRAMEBORDER=\"NO\">\n";



print "<FRAME SRC=\"$location?n=$DATA{'n'}&room=$DATA{'room'}&id=$DATA{'id'}&msg=/bottom\" name=\"message\" SCROLLING=\"no\" BORDERCOLOR=\"0000FF\" MARGINWIDTH=\"0\" MARGINHEIGHT=\"0\">\n";



print "</FRAMESET>\n";        



print "</HTML>";



exit;



}else{



dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);



undef $USER{'frames'};



dbmclose(%USER);


print "Content-type: text/html\n\n";
#print "Pragma: nocache\n";
#print "Cache-Control: no-cache, must-revalidate, no-store\n\n";

undef $frames;


require "$root/inc/print_header.inc";


require "$root/inc/print_room.inc";



require "$root/inc/print_footer.inc";



exit;



}