#!/usr/bin/perl


@who = split(/\s+/, $DATA{'msg'});

if(@who[1] eq ""){

&usersinroom($room);

exit;

}else{



&usersinroom(@who[1]);

exit;
}


sub usersinroom {

        my($whatroom) = @_;

        $c = 0;

        print "Content-type: text/html\n\n";

        require "$root/inc/print_header.inc";

        opendir(USERDIR,"$root/online/users/");
 

         @userdir = readdir(USERDIR);


        closedir(USERDIR);

        print "<center>\n<table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" width=\"97%\">\n";



        foreach $stuff (sort @userdir){

        if ($stuff ne "." && $stuff ne ".."){
 
               $stuff =~ s/.db//;

        dbmopen(%USER,"$root/online/users/$stuff",0777);

        
        if($USER{'room'} eq $whatroom){

 print "<tr>\n<td width=\"21%\">$USER{'nick'}</td>\n";

print "<td width=\"20%\">$USER{'ip'}</td>\n";

print "<td width=\"19%\">$USER{'room'}</td>\n";

print "<td width=\"26%\">$USER{'comment'}</td>\n";


print "<td width=\"20%\">$USER{'mode'}</td>\n</tr>\n";       

dbmclose(%USER);


$c++;
        }else{

dbmclose(%USER);

}


}}
                print "</TABLE></center><p>\n";


print "TOTAL: <b>$c</b><br>\n";

require "$root/inc/check_pm.inc";

require "$root/inc/print_footer.inc";

 }

