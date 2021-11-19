#!/usr/bin/perl





@whois = split(/\s+/, $DATA{'msg'});





if(length(@whois[1]) > 16){





@whois[1]=substr(@whois[1],0,16);





}





if(length(@whois[1]) < 2 && @whois[1] ne '#' && !-e "$root/online/users/@whois[1].db"){



$errors = " Syntax: /whois [nick] /whois [ip] /whois #. A /whois match search must be # or more than two characters.";



return $errors;



exit;





}elsif(@whois[1] eq '#'){



&matchop(@whois[1]);



exit;



}elsif(!-e "$root/online/users/@whois[1].db"){



&matchip(@whois[1]);



exit;



}else{






dbmopen(%USER,"$root/online/users/@whois[1].db",0777);



                $useridletime = <USER>;

        close(USER);





        $whoisidle = $time - $USER{'idle'};





if($USER{'mode'}){



        $errors = " User <B>$USER{'nick'}</B><font size=\"1\" color=\"$iback\">i</font> ($USER{'ip'}) - $USER{'room'}  - Idle: <b>IS AWAY</b>.";





}else{



 $errors = " User <B>$USER{'nick'}</B><font size=\"1\" color=\"$iback\">i</font> ($USER{'ip'}) - $USER{'room'}  - Idle: $whoisidle second(s).";

}





dbmclose(%USER);





return $errors;



exit;



        }

    





sub matchip {



        my($whatroom) = @_;



        $c = 0;



        print "Content-type: text/html\n\n";



        require "$root/inc/print_header.inc";



        opendir(USERDIR,"$root/online/users/");

 



         @userdir = readdir(USERDIR);





        closedir(USERDIR);





         print "<table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" width=\"97%\" align=\"center\">\n";







        foreach $stuff (sort @userdir){



        if ($stuff ne "." && $stuff ne ".."){

 

               $stuff =~ s/.db//;



        dbmopen(%USER,"$root/online/users/$stuff",0777);



        

        if($USER{'ip'} =~ /$whatroom/i){



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

               print "</TABLE><p>\n";







print "TOTAL: <b>$c</b><br>\n";



  require "$root/inc/check_pm.inc";







  require "$root/inc/print_footer.inc";





 }







sub matchop {



        my($whatroom) = @_;



        $c = 0;



        print "Content-type: text/html\n\n";



        require "$root/inc/print_header.inc";



        opendir(USERDIR,"$root/online/users/");

 



         @userdir = readdir(USERDIR);





        closedir(USERDIR);





           print "<table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" width=\"97%\" align=\"center\">\n";





        foreach $stuff (sort @userdir){



        if ($stuff ne "." && $stuff ne ".."){

 

               $stuff =~ s/.db//;



        dbmopen(%USER,"$root/online/users/$stuff",0777);



        

        if($USER{'ip'} =~ '#'){



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

                print "</TABLE><p>\n";







print "TOTAL: <b>$c</b><br>\n";



  require "$root/inc/check_pm.inc";





  require "$root/inc/print_footer.inc";





 



}