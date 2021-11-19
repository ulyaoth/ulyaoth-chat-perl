#!/usr/bin/perl



        print "Content-type: text/html\n\n";

  require "$root/inc/print_header.inc";

 print "<center>\n<table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" width=\"97%\">\n";

print "<tr>\n<td width=\"21%\"><b>nickname</b></td>\n";



print "<td width=\"20%\"><b>ip address</b></td>\n";



print "<td width=\"19%\"><b>room</b></td>\n";



print "<td width=\"26%\"><b>comment</b></td>\n";



print "<td width=\"20%\"><b>mode</b></td>\n</tr>\n";       


$c = 0;

opendir(USERDIR,"$root/online/users/");

flock(USERDIR,2);

foreach $t(sort(grep !/^\./, readdir USERDIR)){




               $t =~ s/.db//ig;

dbmopen(%USER,"$root/online/users/$t",0777);



print "<tr>\n<td width=\"21%\">$USER{'nick'}</td>\n";



print "<td width=\"20%\">$USER{'ip'}</td>\n";



print "<td width=\"19%\">$USER{'room'}</td>\n";



print "<td width=\"26%\">$USER{'comment'}</td>\n";



print "<td width=\"20%\">$USER{'mode'}</td>\n</tr>\n";       



dbmclose(%USER);



$c++;

        }

closedir(USERDIR);



                print "</TABLE></center><P>\n";



print "TOTAL: <b>$c</b><br>\n";

 





        require "$root/inc/check_pm.inc";



      require "$root/inc/print_footer.inc";





       exit;