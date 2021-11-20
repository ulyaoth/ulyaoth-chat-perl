#!/usr/bin/perl

if($frames eq 'yes'){

require "$root/inc/frames_data.inc";

}else{

require "$root/inc/nonframes_data.inc";


}

print $refresher;
print "<HTML>\n<HEAD>\n";

#print $refresher;
#print "<link type=\"text/css\" rel=\"stylesheet\" href=\"/style.css\">\n";

print "<title>$title</title>\n";

print $java;

if ($DATA{'igfocus'}) {

print "<BODY $bgcolor $text onload=\"if (top.location == location) {top.location.href='$location?n=$DATA{'n'}&id=$id&room=$room&msg=/frames#b';};parent.frames[0].scroll(1,10000);\">\n";

} else {

print $body;

}

print $method;

print "<b> $title ( $room )</b>\n<hr>\n";



return true;
