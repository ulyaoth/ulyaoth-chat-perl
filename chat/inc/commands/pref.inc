#!/usr/bin/perl

if($level >= 1){

dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

dbmopen(%PREF,"$root/opspreferences/$realnick.db",0777);

$PREF{'wid'} = $USER{'wid'};

$PREF{'len'} = $USER{'len'};

$PREF{'speed'} = $USER{'speed'};

$PREF{'intro_msg'} = $USER{'intro_msg'};

$PREF{'ips_control'} = $USER{'ips_control'};

$PREF{'comment'} = $USER{'comment'};

$PREF{'auto_replay'} = $USER{'auto_replay'};

$PREF{'menu'} = $USER{'menu'};

$PREF{'nickname'} = $USER{'nickname'};

$PREF{'color'} = $USER{'xcolor'};

$PREF{'font'} = $USER{'font'};

$PREF{'nickcolor'} = $USER{'nickcolor'};

$PREF{'nfont'} = $USER{'nfont'};

$PREF{'ecolor'} = $USER{'ecolor'};

$PREF{'bgcolor'} = $USER{'bgcolor'};

$PREF{'text'} = $USER{'text'};

if($level > 1){

$PREF{'pref_ip'} = $USER{'ip'};

}

dbmclose(%USER);

dbmclose(%PREF);

$errors = " Operator account <b>$realnick</b>.Preferences saved [color wid len comment menu speed pic bg text auto intro ips ip font nfont ncolor].";
        
return $errors;

exit;

}else{

$errors = " Error, command $command not recognized, please use /help for a list of commands.";
        
return $errors;

exit;


}