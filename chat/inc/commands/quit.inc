#!/usr/bin/perl



@words = split(/\s+/,$DATA{'msg'});



open(RO,">>$root/online/rooms/$room.txt");



flock(RO,2);



print RO "<!--servermsg--> *** Signout <B>$DATA{'n'}</B><font size=\"1\" color=\"$iback\">i</font> ($ip).";

 
if ($level >= 1 && @words[1] ne "" && @words[1] ne " "){


open(BANLOG,">>$banlogs");

print BANLOG "*** Signout $DATA{'n'} ($ip).(";


print RO "(";




$it = 0;

foreach $word (@words){



           

$word =~ s/\/quit//g;


print BANLOG "$word ";
                print RO "$word ";



    

                

        }

        print RO ").<br>\n";


print BANLOG "). Time: $fulltime\n";

close(BANLOG);
        close(RO);

}else{



print RO "<br>\n";



close(RO);





}



print "Content-type: text/html\n\n";



print "<HEAD><title>$title</TITLE>\n";



print "</HEAD>\n";



print "<BODY $bgcolor $text onLoad=\"window.status='$version'\">";



print "<FORM METHOD=\"POST\" name=\"msg\" ACTION=\"$location#b\">\n";



print "<b>· $title ($room) 2000 - 2010 © All rights reserved. Please come back soon!!! · </b><hr>\n";





require "$root/inc/print_room.inc";



print "<hr><hr>\n";



print "<center>\n";



print "<p><b>Password is optional for non-Operators</b><p>\n";



print "<table border=\"2\">\n";



print "<tr><td align=right>Nickname </td><td align=left> <input size=14 type=text maxlength=15 name=\"n\" value=\"\">";



print "<tr><td align=right>Password </td><td align=left> <input size=14 type=password maxlength=14 name=\"pass\" value=\"\"></td></tr>";



print "<tr><td align=right>Location </td><td align=left><SELECT NAME=\"room\">";



print "<OPTION value=\"$room\" SELECTED>$room";



foreach $koeng(@rooms){



print "<OPTION value=\"$koeng\">$koeng";



}



print "</SELECT></td></tr>";



print "<tr><td align=right>Frames </td><td align=left><input type=radio name=\"frames\" value=\"yes\"> YES <input type=radio name=\"frames\" checked value=\"\"> NONE</td></tr>";



print "<input type=hidden name=\"w\" value=\"y\">";



print "<tr><td colspan=2 align=center><input type=submit VALUE=\" ENTER CHAT \"></td></tr></table>";



print "</center><p>\n";



print "</form></BODY>";


$kill_user = $DATA{'n'};



require "$root/inc/kill_user.inc";



undef $kill_user;



exit;

