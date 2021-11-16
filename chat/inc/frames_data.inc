#!/usr/bin/perl

$java = "<SCRIPT LANGUAGE=\"JavaScript\"><!-- hide

function m(n) {

parent.frames[1].document.myform.msg.value='m '+n+' ';

}
// --></SCRIPT></HEAD>\n";


$body = "<BODY $bgcolor $text onload=\"if (top.location == location) {top.location.href='$location?n=$DATA{'n'}&id=$id&room=$room&msg=/frames#b';};parent.frames[0].scroll(1,10000);parent.frames[1].document.myform.msg.focus();\">\n";


#$refresher = "<META HTTP-EQUIV=\"refresh\" CONTENT=\"$speed;URL=$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}\#b\">\n";

$refresher = "<META HTTP-EQUIV=\"Refresh\" CONTENT=\"$speed\;URL=$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}\">\n";
             
$method = "";


return true;
