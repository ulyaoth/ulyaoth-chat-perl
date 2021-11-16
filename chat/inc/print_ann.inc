#!/usr/bin/perl


######################## HEADER ###############################################

if($frames eq "yes"){

require "$root/inc/frames_data.inc";

}else{

require "$root/inc/nonframes_data.inc";


}


print $refresher;

print "<HEAD>\n<title>$title</title>\n";

print $java;

print $body;

print $method;

print "<b>$title ($room)</b>\n<hr>\n";

#############################################################################

############################### PRINT ROOM ##################################


open(CHAT, "$root/online/rooms/$room.txt");

flock(CHAT,1);

@chatroom = <CHAT>;

close(CHAT);

@c = reverse(@chatroom);

$len = $len - 1;

@b = @c[0..$len];

@chat = reverse(@b);

foreach $line (@chat) {

$line =~ s/^\<!--(([^ >]|\n)*)-->//ig;

$line =~ s/^\s+//ig;

print $line;

next;
} 

#############################################################################

########################### PRINT ANN #######################################



print "<hr><center><table width=\"500\"><tr><td>\n";

print "<p><center><hr><b>\n";

print "Welcome to $title.\n";

print "<br><br>\n";


print "<font size=+1>\n";

print "$title is pleased to announce its latest version.\n";

print "</center>\n";


print "<p></b>";

print "<br><hr><br>";


print "<p><p>\n";


print "<h4>Additional $title Committee Set Policies</h4><font size=-1>\n";


print "<b>Standard $title Policies / No Modifications</b><p>";

print "<hr><p>\n";

open(ANNCHECK,"$root/boards/loginann.txt");

flock(ANNCHECK,2);

@any = <ANNCHECK>;

close(ANNCHECK);

foreach $ann(@any){

($ann1,$ann2)=split(/\|\"\'\|/,$ann);

$ann2 =~ s/^\<!-- (([^ >]|\n)*) -->//ig;

print $ann2;

}

print "<hr>\n";


print "<p>";

print "</font>\n</td></tr>\n";

print "</table>\n</center></center>\n";

print "<center><p><b><a href=\"$location?n=$DATA{'n'}&id=$id&room=$DATA{'room'}&msg=/friends\">CLICK HERE TO MEET NEW FRIENDS</a></b>\n<p>\n<table border=\"1\" width=\"500\" height=\"1\" bgcolor=\"#E4EEF1\" bordercolor=\"black\">\n";

print "<tr><td width=\"100%\" height=\"1\" align=\"center\" bgcolor=\"#DADADA\" colspan=\"2\">\n";

print "<b>Mister and Miss $title for the month of $amonth<b>\n";

print "</td></tr>\n";


open(M,"$root/boards/mr.txt");

flock(M,1);

$mr = <M>;

close(M);

open(MS,"$root/boards/ms.txt");

flock(MS,1);

$ms = <MS>;

close(MS);


print "<tr><td width=\"50%\" height=\"1\" align=\"center\" bgcolor=\"#FEF5CD\">";

print "<b>Mister: $mr</b>\n</td>\n";

print "<td width=\"50%\" height=\"1\" align=\"center\" bgcolor=\"#FEF5CD\">";

print "<b>Miss: $ms</b>\n</td>\n<tr>\n";


print "</table>\n</center>\n";


print "<a name=\"b\"></a>\n<hr>\n";


dbmopen(%USER,"$root/online/users/$DATA{'n'}",0777);

print $USER{'ann_mess'};

undef $USER{'ann_mess'};

dbmclose(%USER);

open(P,"$root/online/pm/$DATA{'n'}.txt");

flock(P,2);

@p = <P>;

foreach $v(@p){

print $v;

}

close(P);


##############################################################################################################

########################################## PRINT FOOTER #####################################################

if($frames eq "yes"){

print "</body>";

}else{


print "<INPUT TYPE=TEXT NAME=\"msg\" SIZE=$wid MAXLENGTH=400>\n";

print "<INPUT TYPE=HIDDEN NAME=\"n\" VALUE=\"$DATA{'n'}\">";

print "<INPUT TYPE=HIDDEN NAME=\"id\" VALUE=\"$id\">";

print "<br>\n<INPUT TYPE=SUBMIT VALUE=\"  POST  \">\n";

if($menu != 1){

print "<SELECT NAME=\"room\" onchange=\"document.forms[0].submit()\">\n";

print "<OPTION VALUE=\"$room\" SELECTED>$room\n";

foreach $key (@rooms){

print "<OPTION VALUE=\"$key\">$key\n";

}

print "</SELECT>\n";

}else{

print "<INPUT TYPE=HIDDEN NAME=\"room\" VALUE=\"$room\">";

print "<b>| <font size=\"+1\"><a href=\"$location?n=$DATA{'n'}&room=$room&id=$id&msg=/list\">$room</a> </font></b>\n";

}


print "<b> | <a href=\"$location?n=$DATA{'n'}&room=$room&id=$id&msg=/help\"> Help </a> | <a href=\"$location?n=$DATA{'n'}&id=$id&room=$room&msg=/images\"> Images </a> | <a href=\"ops.cgi\" target=_blank> Sign Up </a> | <a href=\"$location?n=$DATA{'n'}&room=$room&id=$id&msg=/quit\"> QUIT </a> |</b</form>\n</body>";

}


return true;

exit;


