#!/usr/local/bin/perl -w

use Time::HiRes qw(usleep ualarm gettimeofday tv_interval);
use Getopt::Long;
use File::Temp;

#use POSIX ":sys_wait_h";

sub timeout {
    my $arg1 = $_[0];
    my $pid = fork();

    if (not defined $pid)
    {
	print "Fork error\n";
	return (0);
    }
    if ($pid == 0) {
	open(STDOUT, ">> $sortie_out");
	open(STDERR, ">> $sortie_err");
	exec($arg1);
    }
    else
    {
	my $cpt = 0;

	while ($cpt < $t * 10)
	{
	    open COM, ("ps -p $pid|grep $pid|" );
	    @lines = <COM>;
	    close COM;

	    if (defined $lines[0] && $lines[0] =~ m/$pid/)
	    {
		if ($lines[0] =~ m/defunct/)
		{
		    return (0);
		}
		else
		{
		    usleep(100000);
		}
	    }
	    else
	    {
		waitpid($pid, 0);
		$ret = $? / 256;

		open(FILE, "> $sortie_ret");
		print FILE $ret;
		close(FILE);

		return (0);
	    }
	    $cpt++;
	}
    }

    $ret = $?;

    open(FILE, "> $sortie_ret");
    print FILE $ret;
    close(FILE);

    open COM, ("ps -p $pid|grep $pid|" );
    my @lines = <COM>;
    close COM;

    if (defined $lines[0] && $lines[0] =~ m/$pid/) {
	kill 9, $pid;
	return (2);
    }
    if ($? > 0)
    {
	return (1);
    }
    else
    {
	return (0);
    }
}

sub test {
    $sortie_out = mktemp("/tmp/tmp.XXXX");
    $sortie_err = mktemp("/tmp/tmp.XXXX");
    $sortie_ret = mktemp("/tmp/tmp.XXXX");

    open(FILE, "> $sortie_out");
    close(FILE);
    open(FILE, "> $sortie_err");
    close(FILE);
    open(FILE, "> $sortie_ret");
    close(FILE);

    ($s1, $usec1) = gettimeofday;

    if (&timeout($_[0]))
    {
	return (0);
	print "\033[0;31mtimeout\033[0;37m\n";
    }
    else
    {
	($s2, $usec2) = gettimeofday;
	$s3 = $s2 - $s1;

	if ($usec2 > $usec1)
	{
	    $usec3 = $usec2 - $usec1;
	}
	else
	{
	    $usec3 = $usec2 - $usec1 + 1000000;
	    $s3 -= 1;
	}

	$nano3 = $usec3 % 1000;
	$usec3 = int($usec3 /1000);

	return (1);
    }
}

sub printResult
{
    my $test = shift(@_);
    return ("\033[0;32mOK\033[0;37m") if ($test);
    return ("\033[0;31mKO\033[0;37m") if (!$test);
}

sub printOk
{
    my $test = shift(@_);
    return ("OK") if ($test);
    return ("KO") if (!$test);
}

sub printColor
{
    my $test = shift(@_);
    return ("good") if ($test);
    return ("fail") if (!$test);
}

sub print_res {
    my $cmd = $_[0];
    $file_number++;
    my $shipcontent = $nom;
    $shipcontent =~ s/\.test/.s/;

    $s3=0;
    $usec3=0;
    $nano3=0;

    &test($cmd);

    system("diff $sortie_ret $test_ret 2> /dev/null 1> /dev/null");
    my $result1 = $?;
    my $res1 = printResult($result1 >> 8 == 0);
    system("diff $sortie_out $test_out 2> /dev/null 1> /dev/null");
    my $result2 = $?;
    my $res2 = printResult($result2 >> 8 == 0);
    system("diff $sortie_err $test_err 2> /dev/null 1> /dev/null");
    my $result3 = $?;
    my $res3 = printResult($result3 >> 8 == 0);
    if ((!$result1) && (!$result2) && (!$result3))
    {
 	$nb_win++;
	$nb_win_dir++;
    }
    $nb_test++;
    $nb_test_dir++;

    my $color1 = printColor ($result1 >> 8 == 0);
    my $color2 = printColor ($result2 >> 8 == 0);
    my $color3 = printColor ($result3 >> 8 == 0);

    my $ok1 = printOk ($result1 >> 8 == 0);
    my $ok2 = printOk ($result2 >> 8 == 0);
    my $ok3 = printOk ($result3 >> 8 == 0);

    open(TEST_DESC, "< $test_desc");
    my $tmp = <TEST_DESC>;
    close(TEST_DESC);
#     if ($cmd =~ /\/([^\/]*)$/)
#     {
# 	$tmp = $1;
#     }

    if ($s3 == 0 && $usec3 == 0 && $nano3 == 0)
    {
	system("
  echo '<tr class=\"timeout\">
	<td>
	  <a href='\\''javascript:Toggle(\"test$file_number\")'\\'' style=\"text-decoration: none\">
	    <img id=\"button_test$file_number\" src=\"img/exp_max.gif\" alt=\"Open\" style=\"border: none\"/>
	  </a>
	  $nom
	</td>
	<td>
	  $tmp
	</td>
	<td class=\"$color1\">
	  $ok1
	</td>
	<td class=\"$color2\">
	  $ok2
	</td>
	<td class=\"$color3\">
	  $ok3
	</td>
      </tr>
      <tr class=\"timeout\" style=\"display:none\" id=\"expand_test$file_number\">
	<td>
	  <p class=\"debug\">' >> index.html;
  perl -pe \"s/\\n/<br \\/>/g\" $nom >> index.html;
  echo	' </p>
        </td>
        <td>
          <p class=\"debug\">' >> index.html;

  perl -pe \"s/ /&nbsp;/g\" $shipcontent | perl -pe \"s/\\n/<br \\/>/g\" >> index.html;

  echo  '  </p>
         </td>
         <td colspan=\"3\" style=\"padding: 0; margin: 0\">
           <div style=\"width: 100%; height: 33%\" class=\"$color1\">
             <p>' >> index.html;

  perl -pe \"s/ /&nbsp;/g\" $sortie_ret | perl -pe \"s/\\n/<br \\/>/g\" >> index.html;

  echo '     </p>
           </div>
           <div style=\"width: 100%; height: 32%; border-top: 1px solid black;
           border-bottom: 1px solid black\" class=\"$color2\">
             <p>' >> index.html;

  perl -pe \"s/ /&nbsp;/g\" $sortie_out | perl -pe \"s/\\n/<br \\/>/g\" >> index.html;

  echo '     </p>
           </div>
           <div style=\"width: 100%; height: 32%\" class=\"$color3\">
             <p>' >> index.html;

  perl -pe \"s/ /&nbsp;/g\" $sortie_err | perl -pe \"s/\\n/<br \\/>/g\" >> index.html;

  echo '     </p>
           </div>
         </td>
      </tr>
' >> index.html
");

	$timeout = "\033[0;31mtimeout\033[0;37m";
	$result = printResult(0);
	format STDOUT1 =
 | @>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>    @*      @*      @*             @*          |
$tmp, $result, $result, $result, $timeout
.
        $~ = STDOUT1;
        if ((!$result1) && (!$result2) && (!$result3))
        {
             $nb_win--;
	     $nb_win_dir--;
        }
   }
    else
    {
        if ((!$result1) && (!$result2) && (!$result3))
        {
           $test_passed = "good";
        }
        else
        {
           $test_passed = "fail";
        }

	system("
  echo '<tr class=\"$test_passed\">
	<td>
	  <a href='\\''javascript:Toggle(\"test$file_number\")'\\'' style=\"text-decoration: none\">
	    <img id=\"button_test$file_number\" src=\"img/exp_max.gif\" alt=\"Open\" style=\"border: none\"/>
	  </a>
	  $nom
	</td>
	<td>
	  $tmp
	</td>
	<td class=\"$color1\">
	  $ok1
	</td>
	<td class=\"$color2\">
	  $ok2
	</td>
	<td class=\"$color3\">
	  $ok3
	</td>
      </tr>
      <tr class=\"$test_passed\" style=\"display:none\" id=\"expand_test$file_number\">
	<td>
	  <p class=\"debug\">' >> index.html;
  perl -pe \"s/\\n/<br \\/>/g\" $nom >> index.html;
  echo	' </p>
        </td>
        <td>
          <p class=\"debug\">' >> index.html;

  perl -pe \"s/ /&nbsp;/g\" $shipcontent | perl -pe \"s/\\n/<br \\/>/g\" >> index.html;

  echo  '  </p>
         </td>
         <td colspan=\"3\" style=\"padding: 0; margin: 0\">
           <div style=\"width: 100%; height: 33%\" class=\"$color1\">
             <p>' >> index.html;

  perl -pe \"s/ /&nbsp;/g\" $sortie_ret | perl -pe \"s/\\n/<br \\/>/g\" >> index.html;

  echo '     </p>
           </div>
           <div style=\"width: 100%; height: 32%; border-top: 1px solid black;
           border-bottom: 1px solid black\" class=\"$color2\">
             <p>' >> index.html;

  perl -pe \"s/ /&nbsp;/g\" $sortie_out | perl -pe \"s/\\n/<br \\/>/g\" >> index.html;

  echo '     </p>
           </div>
           <div style=\"width: 100%; height: 32%\" class=\"$color3\">
             <p>' >> index.html;

  perl -pe \"s/ /&nbsp;/g\" $sortie_err | perl -pe \"s/\\n/<br \\/>/g\" >> index.html;

  echo '     </p>
           </div>
         </td>
      </tr>
' >> index.html
");


	format STDOUT2 =
 | @>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>    @*      @*      @*    @### s  @### us  @### ns  |
$tmp, $res1, $res2, $res3, $s3, $usec3, $nano3
.
        $~ = STDOUT2;
    }

    if (!(defined $f) && !(defined $n) && (!defined $c))
    {
        write;
    }
    unlink("$sortie_ret");
    unlink("$sortie_err");
    unlink("$sortie_out");
    unlink $test_desc;
    unlink $test_in;
    unlink $test_out;
    unlink $test_err;
    unlink $test_ret;
}

sub display_folder {
    use IO::Dir;
    my ($dir) = @_;
    my $d = IO::Dir->new();
    $d->open($dir);
    if (defined $d) {
	while (defined($_ = $d->read)) {
	    my $tmp = $_;
	    my $filename = File::Spec->catfile($dir, $tmp);
	    print "\033[0;33m", $tmp, "\033[0;37m\n" if (-d $tmp && $tmp !~ /\..*/);
	    &display_folder($filename) if (-d $tmp && $tmp !~ /\..*/);
	    print "\033[0;36m", $tmp, "\033[0;37m\n" if (-f $tmp);
	}
	undef $d;
    }
}

sub lister_fichiers_recur {
    my ($repertoire) = @_;
    my @fichiers = ();
    opendir (my $rep_fh, $repertoire)
	or die "$repertoire: file not found\n";
    my @file_rep = readdir($rep_fh);
    closedir ($rep_fh);

    foreach my $nom (@file_rep) {
	if ( -f "$repertoire/$nom") {
	    push (@fichiers, "$repertoire/$nom");
	}
	elsif ( -d "$repertoire/$nom" && "$nom" !~ /\..*/ && "$nom" !~ /samples/) {
	    push (@fichiers, "$repertoire/$nom");
	    push (@fichiers, &lister_fichiers_recur("$repertoire/$nom"));
	}
    }
    return @fichiers;
}

sub print_folder {
    $nb_test_dir = 0;
    $nb_win_dir = 0;
    my @file_rep = @_;
    foreach $nom (@file_rep) {
	if ( -f "$nom") {
	}
	elsif ( -d "$nom" && "$nom" !~ /.\/img/) {
	    if ((defined $c) && ($nb_test_dir != 0))
 	    {
		$nb_win_dir = $nb_win_dir / $nb_test_dir * 100;
		print "\033[0;32m$nb_win_dir %\n\033[0;37m";
 	    }
	    if (defined $c) {
		$nb_test_dir = 0;
		$nb_win_dir = 0;
		print "\033[0;36m$nom \033[0;37m";
	    }
	    if (!(defined $f) && !(defined $n) && (!defined $c))
	    {
		$category_number++;
if ($file_number != 0)
{
    system ("
    echo '
      </table>
    </td>
  </tr>' >> index.html
");
}
		system ("
echo '
  <tr>
    <td style=\"padding-left: 2px\">
      <a href='\\''javascript:Toggle(\"cat$category_number\")'\\'' style=\"text-decoration: none\">
        <img id=\"button_cat$category_number\" src=\"img/exp_max.gif\" alt=\"Open\" style=\"border: none\"/>
      </a>
      $nom
    </td>
  </tr>
  <tr id=\"expand_cat$category_number\" style=\"display:none\">
    <td style=\"padding-left: 20px\">
      <table border=\"1\" style=\"width:100%; border-collapse: collapse;\">
        <tr>
          <th>
            Name
          </th>
          <th style=\"width: 50%\">
  	    Desc
          </th>
          <th>
 	    RETURN
          </th>
          <th>
 	    STDOUT
          </th>
          <th>
	    STDERR
          </th>
        </tr>
' >> index.html
");
		print " --------------------------------------------------------------------------------------|\n\033[0;33mcategory:\033[0;36m $nom:\033[0;37m\n";
		print "\t\t\t\t     RETURN  STDOUT  STDERR\t   EXECUTION TIME\n";
	    }
	}
	if ( -f "$nom" && "$nom" =~ /\.test$/) {
	    &treat_file("$nom");
	}
    }
}

sub treat_file {
    open(FILE, $_[0]);
    $test_desc = mktemp("/tmp/tmp.XXXX");
    $test_in = mktemp("/tmp/tmp.XXXX");
    $test_out = mktemp("/tmp/tmp.XXXX");
    $test_err = mktemp("/tmp/tmp.XXXX");
    $test_ret = mktemp("/tmp/tmp.XXXX");
    my $lines = <FILE>;

    if ("$lines" =~ /desc:$/)
    {
	open(TEST_DESC,">> $test_desc");
	$lines = <FILE>;
	while ($lines !~ /in:/)
	{
	    print TEST_DESC $lines;
	    $lines = <FILE>;
	}
	close(TEST_DESC);
    }
    if ($lines =~ /in:/)
    {
	open(TEST_IN,">> $test_in");
	$lines = <FILE>;
	while ($lines !~ /out:/)
	{
	    print TEST_IN $lines;
	    $lines = <FILE>;
	}
	close(TEST_IN);
    }
    if ($lines =~ /out:$/)
    {
	open(TEST_OUT,">> $test_out");
	$lines = <FILE>;
	while ($lines !~ /err:/)
	{
	    print TEST_OUT $lines;
	    $lines = <FILE>;
	}
	close(TEST_OUT);
    }
    elsif ("$lines" =~ /out:(.*)/)
    {
	system("$1 > $test_out 2> /dev/null");
	$lines = <FILE>;
    }
    if ($lines =~ /err:$/)
    {
	open(TEST_ERR,">> $test_err");
	$lines = <FILE>;
	while ($lines !~ /ret:/)
	{
	    print TEST_ERR $lines;
	    $lines = <FILE>;
	}
	close(TEST_ERR);
    }
    elsif ("$lines" =~ /err:(.*)/)
    {
	system("$1 2> $test_err > /dev/null");
	$lines = <FILE>;
    }
    if ($lines =~ /ret:$/)
    {
	open(TEST_RET,">> $test_ret");
	$lines = <FILE>;
	while ($lines)
	{
	    $lines =~ /(.*)\n/;
	    print TEST_RET $1;
	    $lines = <FILE>;
	}
	close(TEST_RET);
    }
    elsif ("$lines" =~ /ret:(.*)/)
    {
	system("$1 > /dev/null 2> /dev/null ;echo -n \$? > $test_ret");
	$lines = <FILE>;
    }
    close(FILE);

    open(FILE1, $test_in);
    my $line = <FILE1>;
    &print_res($line);
    close(FILE1);
}

sub test_all {

    system ("
echo '<html>
  <head>
    <title>test</title>

    <script type=\"text/javascript\" src=\"codejava.js\"></script>
    <style type=\"text/css\">
      body
      {
        background-repeat:repeat-x;
        background-image: url(img/back.gif);
      }

      td
      {
        padding: 2px;
      }

      html
      {
        font-size: 12px;
        margin: 2px;
      }

      td
      {
        font-size: 12px;
      }

      th
      {
        font-size: 13px;
      }

      p
      {
        font-size: 12px;
        margin: 2px;
      }

      .fail
      {
        background-color: #e3b3be;
      }

      .good
      {
        background-color: #ddffef;
      }

      .timeout
      {
        background-color: #ccb9f2;
      }

      .debug
      {
        margin: 10px;
      }

    </style>
  </head>

  <body>
    <div style=\"float: left\">
      <img src=\"img/tiger.jpg\" title=\"tigrou\" alt=\"tigrou\" height=\"150\"/>
    </div>
    <div style=\"float: left\">
      <pre>

  _____            __          __
 / ____|           \\ \\        / /
| |     ___  _ __ __\\ \\  /\\  / /_ _ _ __
| |    / _ \\| |__/ _ \\ \\/  \\/ / _` | |__|
| |___| (_) | | |  __/\\  /\\  / (_| | |
 \\_____\\___/|_|  \\___| \\/  \\/ \\__,_|_|
      </pre>
    </div>
    <div style=\"clear: left\">
    </div>
    <table border=\"1\" style=\"width:90%; border-collapse: collapse;\">
      <tr>
	<th>
	  Category
	</th>
      </tr>' > index.html
");

    @folder = &lister_fichiers_recur(".");
    &print_folder(@folder);
}

sub lib {
    if (defined $e)
    {
	# BEGIN OF FILE

	$nom2= $_[0];
	print " --------------------------------------------------------------------------------------|\n\033[0;33mcategory:\033[0;36m $nom2:\033[0;37m\n";
	print "\t\t\t\t     RETURN  STDOUT  STDERR\t   EXECUTION TIME\n";
    }
    @folder = &lister_fichiers_recur($_[0]);
    &print_folder(@folder);
}

$nb_test = 0;
$nb_win = 0;
$t = 20;
$a = 1;
GetOptions("c|categories" => \$c,
	   "e|select=s" => \$e,
	   "f|final" => \$f,
	   "n|number" => \$n,
	   "a|all" => \$a,
	   "h|help" => \$h,
	   "t|timer=f" => \$t);
if (defined $h)
{
    print "Help of test suite\n\n";
    print "Usage: ./timer.pl [-a|-e folder] [-n|-f|-c] [-t time]\n\n";
    print "-c or -categories:\tSelect a category \n";
    print "-e or -select:\t\tSelect a folder\n";
    print "-f or -final:\t\tSelect the percentage of succeful test\n";
    print "-n or -number:\t\tPrint the number of succeful test\n";
    print "-a or -all:\t\tTest all categories\n";
    print "-h or -help:\t\tPrint this message\n";
    print "-t or -timeout:\t\tHere you can change the timeout\n\n";
    print "Made for 42sh project\n";
    exit(0);
}

$category_number = 0;
$file_number = 0;
&lib($e) if defined $e;
&test_all() if ((defined $a) && (!defined $e));
print "You need some help ?
please set an option\n" if (!(defined $c)
			    && !(defined $e)
			    && !(defined $f)
			    && !(defined $n)
			    && !(defined $a)
			    && !(defined $t));
print "Wrong option:\n" if $ARGV[0];
 foreach (@ARGV) {
    print "$_\n";
}
if ((not defined $n) && (not defined $f) && ($nb_test != 0))
{
    $nb_perc = $nb_win / $nb_test *100;
    print "\n\033[0;36mpercentage of tests succesful: \033[0;37m_________________________________________________ \033[0;32m$nb_perc%\033[0;37m\n";

    if ($file_number != 0)
    {
	system ("
  echo '
    </table>
' >> index.html
");
    }
    if ($nb_perc == 100)
    {
	$color = "good";
    }
    else
    {
	$color = "fail";
    }
    system ("
 echo '
        </td>
      </tr>
      <tr>
        <td  class=\"$color\" align=\"right\">
          <p>
            Percentage of successful test: $nb_perc %
          </p>
        </td>
      </tr>
    </table>
  </body>
</html>' >> index.html
");

}
if ((defined $f) && ($nb_test != 0))
{
    $nb_perc = $nb_win / $nb_test *100;
    print "\033[0;36mpercentage of tests succesful: \033[0;37m \033[0;32m$nb_perc%\033[0;37m\n";
}
if ($f && $nb_test == 0)
{
    print "\033[0;31mno test to do%\n\033[0;37m";
}
if ((defined $c) && ($nb_test_dir != 0))
{
    $nb_win_dir = $nb_win_dir / $nb_test_dir * 100;
    print "\033[0;32m$nb_win_dir%\n\033[0;37m";
}
if ($n)
{
    print "\033[0;36mnumber of tests: \033[0;32m$nb_win\033[0;37m / $nb_test\n";
}
