#!/usr/bin/perl

use CGI;
use Fcntl;
use DB_File;

$root = '/opt/ulyaoth/chat';

$sendmail = "/usr/lib/sendmail";

$title = "Ulyaoth Chat";

&data();


$max_ops_rank = "15";  

$comm_rank = "50";  

$max_comm_rank = "100";  

$staff_rank = "120";  

$max_staff_rank = "150";  

$admin_rank = "190";  



#idle them

opendir(DIR,"$root/cp/");

foreach $xxx(sort(grep !/^\./, readdir DIR)){

$xxx =~ s/.db//ig;

dbmopen(%A,"$root/cp/$xxx",0777);

$aa = time();

$checky = $aa - $A{'time'};

dbmclose(%A);

if($checky > 600){

unlink ("$root/cp/$xxx.db");

		}

}


if($DATA{'ops'} =~ /[\W]/ or !$DATA{'ops'} or length($DATA{'ops'}) > 14 or !-e "$root/ops/ops/$DATA{'ops'}.db"){

$error = "Control Panel, please login!";

require "$root/cpinc/login.inc";

exit;


} 



if($DATA{'a'} eq "login"){

dbmopen(%O,"$root/ops/ops/$DATA{'ops'}",0777);

$pass = crypt($DATA{'password'}, "Cd");

$pa = $O{'password'};

dbmclose(%O);

if ($pa ne $pass){

$error = "<font color=\"red\">Incorrect Password, please try again!</font>";

require "$root/cpinc/login.inc";

exit;

}else{

dbmopen(%CP,"$root/cp/$DATA{'ops'}",0777);

for (0..9) { $id .= pack("C",65+int(rand(25.9999))); }

$CP{'s'} = $id;

$CP{'time'} = time();

dbmclose(%OPS);


print "Content-type: text/html\n\n";

require "$root/cpinc/frames.inc";

exit;


		}


}


if(-e "$root/cp/$DATA{'ops'}.db"){

dbmopen(%CP,"$root/cp/$DATA{'ops'}",0777);

if($CP{'s'} ne $DATA{'s'}){

$error = "<font color=\"red\">Incorrect Password, please try again!</font>";

require "$root/cpinc/login.inc";

exit;

	}

}else{

$error = " Control Panel, please login!";

require "$root/cpinc/login.inc";

exit;


}

#side

if($DATA{'a'} eq "side"){

require "$root/cpinc/side.inc";

exit;

}

#main

if($DATA{'a'} eq "main"){

require "$root/cpinc/main.inc";

exit;

}

#account

if($DATA{'a'} eq "account"){

require "$root/cpinc/account.inc";

exit;

}


#profile

if($DATA{'a'} eq "profile"){


require "$root/cpinc/profile.inc";

exit;

}


#pass

if($DATA{'a'} eq "pass"){

require "$root/cpinc/pass.inc";

exit;

}

#online

if($DATA{'a'} eq "online"){

require "$root/cpinc/online.inc";

exit;

}

#out

if($DATA{'a'} eq "out"){

require "$root/cpinc/out.inc";

exit;

}

#complain

if($DATA{'a'} eq "complain"){

require "$root/cpinc/complain.inc";

exit;

}

#mail

if($DATA{'a'} eq "cmail"){

require "$root/cpinc/mail.inc";

exit;

}
#del

if($DATA{'a'} eq "del"){

require "$root/cpinc/del.inc";

exit;

}

#sendmail

if($DATA{'a'} eq "sendmail"){

require "$root/cpinc/sendmail.inc";

exit;

}


#sendmail

if($DATA{'a'} eq "create"){

require "$root/cpinc/create.inc";

exit;

}

#sendmail

if($DATA{'a'} eq "money"){

require "$root/cpinc/money.inc";

exit;

}

#sendmail

if($DATA{'a'} eq "agents"){

require "$root/cpinc/agents.inc";

exit;

}

#sendmail

if($DATA{'a'} eq "editagents"){

require "$root/cpinc/editagents.inc";

exit;

}


#sendmail

if($DATA{'a'} eq "database"){

require "$root/cpinc/database.inc";

exit;

}

#sendmail

if($DATA{'a'} eq "renew"){

require "$root/cpinc/renew.inc";

exit;

}

#sendmail

if($DATA{'a'} eq "nchange"){

require "$root/cpinc/nchange.inc";

exit;

}


sub data {
$request_method = $ENV{'REQUEST_METHOD'};
if ($request_method eq "GET") {
        $form_info = $ENV{'QUERY_STRING'};
} else {
        $size_of_form_information = $ENV{'CONTENT_LENGTH'};
        read (STDIN, $form_info, $size_of_form_information);
}
@key_value_pairs = split (/&/, $form_info);
foreach $key_value (@key_value_pairs) {
        ($key, $value) = split (/=/, $key_value);

        $value =~ tr/+/ /;
        $value =~ s/%([\dA-Fa-f][\dA-Fa-f])/pack ("C", hex ($1))/eg;
        if (defined($DATA{$key})) {
                $DATA{$key} = join (", ", $DATA{$key}, $value);
        } else {
                $DATA{$key} = $value;
        }
}
}