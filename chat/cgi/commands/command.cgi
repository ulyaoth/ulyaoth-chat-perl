#!/usr/bin/perl

require "$root/inc/variables.inc";

foreach $key (@cmds){

if($command eq $key){

$good_cmd = 1;

}}

if($good_cmd ne 1){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";


}else{

require "$root/inc/commands/$command.inc";

}

print "Content-type: text/html\n\n";



&header;

&room;

if($frames ne 'yes'){

&footer;

}

sub room{

require "$root/inc/print_room.inc";
}



sub header {

if($frames eq 'yes'){

require "$root/inc/frames_data.inc";

}else{

require "$root/inc/nonframes_data.inc";

}


if($mkframe == 1){

$java = "<SCRIPT LANGUAGE=\"JavaScript\"><!-- hide

function chroom() {
 parent.frames[1].location='$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}&msg=/bottom';}
function m(n) {
 parent.frames[1].document.myform.msg.value='m '+n+' ';
}
// --></SCRIPT></HEAD>";

}


if($frames eq 'yes'){

$body = "<BODY $bgcolor $text onLoad=\"window.status='$version';if (top.location == location) {top.location.href='$location?n=$DATA{'n'}&room=$room&id=$id&msg=/frames';}\">\n";

$method = "";


}else{

$method = "<FORM METHOD=\"POST\" NAME=\"msg\" ACTION=\"$location#b\">\n";

$body = "<BODY $bgcolor $text onLoad=\"window.status='$version';if (window != top) {top.location.href='$location?n=$DATA{'n'}&id=$id&room=$room';};document.forms[0].msg.focus()\">\n";

}

if($mkframe == 1){

$body = "<BODY $bgcolor onLoad=\"window.status='$version';chroom()\">\n";

}

if($mkframe == 1 or $frames eq 'yes'){

print "<META HTTP-EQUIV=\"Refresh\" CONTENT=\"$speed;URL=$location?n=$DATA{'n'}&room=$room&id=$id\">\n";

}else{


print "<META HTTP-EQUIV=\"Refresh\" CONTENT=\"300;URL=$location?n=$DATA{'n'}&id=$id&room=$room\">\n";

}

print "<HEAD><title>$title</TITLE>\n";

#print "<link type=\"text/css\" rel=\"stylesheet\" href=\"/style.css\">\n";


print $java;

print $body;

print $method;




print "<b>$title ( $room )</b>\n<hr>\n";



}


sub footer {


require "$root/inc/print_footer.inc";

}