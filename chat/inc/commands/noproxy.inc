#!/usr/bin/perl



if ($command eq '/noproxy' && $level >= 15){

 

@proxy = split(/\s+/, $DATA{'msg'});



if(@proxy[1] ne '-'){



open(WRPROXYTIME,">$root/online/noproxy/proxy.txt");



print WRPROXYTIME $time;



close(WRPROXYTIME);





open(PROXYROOM,">>$root/online/rooms/$room.txt");



print PROXYROOM "<!--servermsg--> *** Proxy entry denied for 30 minutes by Ops <b>$DATA{'n'}</b><font size=\"1\" color=\"$iback\">i</font>.<br>\n";



close(PROXYROOM);





opendir(ALLACTION,"$root/online/action/");



 @mesaction = readdir(ALLACTION);



        closedir(ALLACTION);





foreach $i(@mesaction){



open(MESPRIV,">>$root/online/pm/$i");



print MESPRIV "<!-- $time --> *** NO PROXY: Proxy entry denied for 30 minutes by Ops <B>$DATA{'n'}</b><font size=\"1\" color=\"$iback\">i</font> ($realnick) ($room).<br>\n";



close(MESPRIV);



}







$errors = " No proxy <b>ON</b>. Proxy entry denied.";



return $errors;



exit;





}



if(@proxy[1] eq '-'){



unlink ("$root/online/noproxy/proxy.txt");





opendir(ALLACTION,"$root/online/action/");



 @mesaction = readdir(ALLACTION);



        closedir(ALLACTION);





foreach $i(@mesaction){



 open(MESPRIV,">>$root/online/pm/$i");



print MESPRIV "<!-- $time --> *** NO PROXY: Proxy entry allowed by Ops <B>$DATA{'n'}</b> <font size=\"1\" color=\"$iback\">i</font>($realnick) ($room).<br>\n";



close(MESPRIV);



}



$errors = " No proxy <b>OFF</b>. Proxy entry allowed.";





return $errors;



exit;



}







}elsif ($command eq '/noproxy' && $level < 15){

                



        $errors = " Error, command $command not recognized, please use /help for a list of commands.";





return $errors;



exit;





}