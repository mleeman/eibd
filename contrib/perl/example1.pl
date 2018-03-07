# written by Michael Markstaller <mm@elabnet.de>
# published under the GPL V2 (based on Misterhouse code)

# encode DPT9.001/EIS 5
sub decode_dpt9 {
    my @data = @_;
    my $res;

    unless ($#data == 2) {
    	($data[1],$data[2]) = split(' ',$data[0]);
    	$data[1] = hex $data[1];
    	$data[2] = hex $data[2];
      unless (defined $data[2]) {
        return;
      }
    }
    my $sign = $data[1] & 0x80;
    my $exp = ($data[1] & 0x78) >> 3;
    my $mant = (($data[1] & 0x7) << 8) | $data[2];

    $mant = -(~($mant - 1) & 0x7ff) if $sign != 0;
    $res = (1 << $exp) * 0.01 * $mant;
    return $res;
}

sub encode_dpt9 { # 2byte signed float
    my $state = shift;
    my $data;

	my $sign = ($state <0 ? 0x8000 : 0);
    my $exp  = 0;
    my $mant = 0;

    $mant = int($state * 100.0);
    while (abs($mant) > 2047) {
        $mant = $mant >> 1;
        $exp++;
    }
    $data = $sign | ($exp << 11) | ($mant & 0x07ff);
    return $data >> 8, $data & 0xff;
}

sub decode_dpt4 { #1byte char
    return sprintf("%c", hex(shift));
}

sub decode_dpt5 { #1byte unsigned percent
    return sprintf("%.1f", hex(shift) * 100 / 255);
}

sub decode_dpt6 { #1byte signed 
    my $val = hex(shift);
    return $val > 127 ? $val-256 : $val;
}

sub decode_dpt7 { #2byte unsigned 
    my @val = split(" ",shift);
    return (hex($val[0])<<8) + hex($val[1]);
}

sub decode_dpt8 { #2byte signed 
    my @val = split(" ",shift);
    my $val2 = (hex($val[0])<<8) + hex($val[1]);
    return $val2 > 32767 ? $val2-65536 : $val2;
}

sub decode_dpt10 { #3byte time
    my @val = split(" ",shift);
    my @wd = qw(Null Mo Di Mi Do Fr Sa So);
    $val[0] = hex($val[0]);
    $val[1] = hex($val[1]);
    $val[2] = hex($val[2]);
    unless ($val[2]) { return; }
    my $day = ($val[0] & 0xE0) >> 5;
    my $hour    = $val[0] & 0x1F;
    my $minute  = $val[1];
    my $second  = $val[2];
    return sprintf("%s %02i:%02i:%02i",$wd[$day],$hour,$minute,$second);
}

sub decode_dpt11 { #3byte date
    my @val = split(" ",shift);
    my @wd = qw(Null Mo Di Mi Do Fr Sa So);
    $val[0] = hex($val[0]);
    $val[1] = hex($val[1]);
    $val[2] = hex($val[2]);
    unless ($val[2]) { return; }
    my $mday    = $val[0] & 0x1F;
    my $mon     = $val[1] & 0x0F;
    my $year    = $val[2] & 0x7F;
    $year = $year < 90 ? $year+2000 : $year+1900; # 1990 - 2089
    return sprintf("%04i-%02i-%02i",$year,$mon,$mday);
}

sub decode_dpt12 { #4byte unsigned 
    my @val = split(" ",shift);
    return (hex($val[0])<<24) + (hex($val[1])<<16) + (hex($val[2])<<8) + hex($val[3]);
}

sub decode_dpt13 { #4byte signed 
    my @val = split(" ",shift);
    my $val2 = (hex($val[0])<<24) + (hex($val[1])<<16) + (hex($val[2])<<8) + hex($val[3]);
    return $val2 >  2147483647 ? $val2-4294967296 : $val2;
}

sub decode_dpt14 { #4byte float
    #Perls unpack for float is somehow strange broken
    my @val = split(" ",shift);
    my $val2 = (hex($val[0])<<24) + (hex($val[1])<<16) + (hex($val[2])<<8) + hex($val[3]);
    my $sign = ($val2 & 0x80000000) ? -1 : 1;
    my $expo = (($val2 & 0x7F800000) >> 23) - 127;
    my $mant = ($val2 & 0x007FFFFF | 0x00800000);
    my $num = $sign * (2 ** $expo) * ( $mant / (1 << 23));
    return sprintf("%.4f",$num);
}

sub decode_dpt16 { # 14byte char
    my @val = split(" ",shift);
    my $chars;
    for (my $i=0;$i<14;$i++) {
        $chars .= sprintf("%c", hex($val[$i]));
    }
    return sprintf("%s",$chars);
}

sub encode_dpt5 {
    my $state = shift;
    my $newval;
    if ($state =~ /^(\d+)$/) {
    	$newval = $1;
    }
    $newval = 100 if ($newval > 100);
    $newval = 0 if ($newval < 0);;
    my $byte = sprintf ("%.0f", $newval * 255 / 100);
    return($byte);
}

sub decode_dpt {
    my $dst = shift;
    my $data = shift;
    my $dpt = shift;
    my $value;
    my $dptid = $eibgaconf{$dst}{'DPTId'} || $dpt || 0;
    switch ($dptid) {
            case 1 { $value = int($data) }
            case 2 { $value = int($data) } # somehow wrong 2bit
            case 3 { $value = int($data) } # somehow wrong 4bit
            case 4 { $value = decode_dpt4($data) } 
            case 5 { $value = decode_dpt5($data) }
            case 6 { $value = decode_dpt6($data) }
            case 7 { $value = decode_dpt7($data) }
            case 8 { $value = decode_dpt8($data) }
            case 9 { $value = decode_dpt9($data) }
            case 10 { $value = decode_dpt10($data) }
            case 11 { $value = decode_dpt11($data) }
            case 12 { $value = decode_dpt12($data) }
            case 13 { $value = decode_dpt13($data) }
            case 14 { $value = decode_dpt14($data) }
            case 16 { $value = decode_dpt16($data) }
            else   { return; } # nothing
    }
    return $value;
}

sub decode_vbusmonitor{
    my $buf = shift;
    my %msg;
    my @data;
    my ($type, $src, $dst, $drl, $bytes) = unpack("CnnCa*", $buf);
    @data = unpack ("C" . bytes::length($bytes), $bytes);
    
    my $apci;

    # For mapping between APCI symbols and values, not fully implemented!
    my @apcicodes = qw (A_GroupValue_Read A_GroupValue_Response A_GroupValue_Write 
        A_PhysicalAddress_Write A_PhysicalAddress_Read A_PhysicalAddress_Response
        A_ADC_Read A_ADC_Response A_Memory_Read A_Memory_Response A_Memory_Write
        A_UserMemory A_DeviceDescriptor_Read A_DeviceDescriptor_Response A_Restart
        A_OTHER); # not fully implemented
    my @tpducodes = qw(T_DATA_XXX_REQ T_DATA_CONNECTED_REQ T_DISCONNECT_REQ T_ACK);
    
    $msg{'repeated'} = (($type & 0x20) >> 5) ^ 0b01;
    # priority class b00, b01, b10, b11
    my @prioclasses = qw(system alarm high low);
    $msg{'class'} = @prioclasses[($type & 0xC) >> 2];
    
    #DRL
    $msg{'rcount'} = ($drl & 0x70)>>4;
    $msg{'datalen'} = ($drl & 0x0F);
    $msg{'tpdu_type'} = $tpducodes[($data[0] & 0xC0)>>6];
    $msg{'sequence'} = ($data[0] & 0x3C)>>2;
    $msg{'apci'} = @apcicodes[(($data[0] & 0x03)<<2) | (($data[1] & 0xC0)>>6)];
    if ($msg{'tpdu_type'} eq "T_DATA_XXX_REQ" and $msg{'datalen'} == 1) { # 6bit only
        $msg{'data'} = sprintf("%02X", ($data[1] & 0x3F));
    } elsif ($msg{'tpdu_type'} eq "T_DATA_XXX_REQ" and $msg{'datalen'} > 1) {
        for (my $i=2; $i<= $msg{'datalen'}; $i++) {
          $msg{'data'} = $msg{'data'} . sprintf("%02X ", ($data[$i]));
        }
    } else {
        #DEBUG("OTHER R:$msg{'repeated'} P:$msg{'class'} Hops:$msg{'rcount'} T:$msg{'tpdu_type'} Seq:$msg{'sequence'} A:$msg{'apci'} src: $msg{'src'} dst: $msg{'dst'} len: $msg{'datalen'} data: @data");
    } 
    $msg{'data'} = trim($msg{'data'});
    $msg{'src'} = addr2str($src);
    $msg{'dst'} = addr2str($dst, $drl>>7);
    $msg{'value'} = decode_dpt($msg{'dst'},$msg{'data'});
    DEBUG("R:$msg{'repeated'} P:$msg{'class'} Hops:$msg{'rcount'} T:$msg{'tpdu_type'} Seq:$msg{'sequence'} A:$msg{'apci'} src: $msg{'src'} dst: $msg{'dst'} len: $msg{'datalen'} data: $msg{'data'} ($msg{'value'})");

    #$msg{'data'} = \@data;
    $msg{'buf'} = unpack ("H*", $buf);
    return %msg;
}

sub knx_read {
  my $dst = $_[0];
  my $age = $_[1] || 0; # read hot unless defined
  my $dpt = $_[2];
  my $src=EIBConnection::EIBAddr();
  my $buf=EIBConnection::EIBBuffer();
  my $hexbytes;
  my $leibcon = EIBConnection->EIBSocketURL($eib_url) or return("Error: $!");
  my $res=$leibcon->EIB_Cache_Read_Sync(str2addr($dst), $src, $buf, $age);
  if (!defined $res) { return; } # ("ReadError: $!");
  $leibcon->EIBClose();
  # $$src contains source PA
  
  my @data = unpack ("C" . bytes::length($$buf), $$buf);
  if ($res == 2) { # 6bit only
     return sprintf("%02X", ($data[1] & 0x3F));
  } else {
     for (my $i=2; $i<= $res-1; $i++) {
         $hexbytes = $hexbytes . sprintf("%02X ", ($data[$i]));
     }
     return decode_dpt($dst,$hexbytes,$dpt);
  } 
}

sub knx_write {
  my ($dst,$value,$dpt) = @_;
  my $bytes;
 $dpt = $eibgaconf{$dst}{'DPTId'} unless $dpt; # read dpt from eibgaconf if existing
  switch ($dpt) {
          case [1..3] { $bytes = pack ("CC", 0, 0x80 | ($value & 0x3f)) } #send 6bit small
          case 4      { $bytes = pack ("CCc", 0, 0x80, ord($value)) } 
          case 5      { $bytes = pack ("CCC", 0, 0x80, encode_dpt5($value)) } #EIS 6/DPT5.001 1byte
          case 6      { $bytes = pack ("CCc", 0, 0x80, $value) }
          case 7      { $bytes = pack ("CCS>", 0, 0x80, $value) }
          case 7      { $bytes = pack ("CCs>", 0, 0x80, $value) } 
          case 9      { $bytes = pack ("CCCC", 0, 0x80, encode_dpt9($value)) } #EIS5/DPT9 2byte float 
          case 12     { $bytes = pack ("CCL>", 0, 0x80, $value) }  #EIS11.000/DPT12 (4 byte unsigned)
          case 13     { $bytes = pack ("CCl>", 0, 0x80, $value) }
          case 14     { $bytes = pack ("CCf>", 0, 0x80, $value) }
          case 16     { $bytes = pack ("CCa14", 0, 0x80, $value) }
          else        { return; }
  }
  my $leibcon = EIBConnection->EIBSocketURL($eib_url) or return("Error opening con: $!");
  if ($leibcon->EIBOpenT_Group(str2addr($dst),1) == -1) { return("Error opening group: $!"); } 
  my $res=$leibcon->EIBSendAPDU($bytes);
  $leibcon->EIBClose();
  return $res;
}

# addr2str: Convert an integer to an EIB address string, in the form "1/2/3" or "1.2.3"
sub addr2str {
    my $a = $_[0];
    my $b = $_[1] || 0;  # 1 if local (group) address, else physical address
    my $str ;
    if ($b == 1) { # logical address used
        $str = sprintf "%d/%d/%d", ($a >> 11) & 0xf, ($a >> 8) & 0x7, $a & 0xff;
    }
    else { # physical address used
        $str = sprintf "%d.%d.%d", $a >> 12, ($a >> 8) & 0xf, $a & 0xff;
    }
    return $str;
}

# str2addr: Convert an EIB address string in the form "1/2/3" or "1.2.3" to an integer
sub str2addr {
    my $str = $_[0];
    if ($str =~ /(\d+)\/(\d+)\/(\d+)/) { # logical address
        return ($1 << 11) | ($2 << 8) | $3;
    }
    elsif ($str =~ /(\d+)\.(\d+)\.(\d+)/) { # physical address
        return ($1 << 12) | ($2 << 8) | $3;
    }
    else
    {
	print "Bad EIB address string: \'$str\'\n";
	return;
    }
}


# ....(Main loop)....
use Log::Log4perl qw(:easy get_logger);
Log::Log4perl->easy_init($DEBUG);
use IO::Select;
use Config::Std { def_sep => '=', read_config => 'my_read_cfg', write_config => 'my_write_cfg' };
use EIBConnection;
my %eibgaconf;
if (-e '/etc/wiregate/eibga.conf') { 
    my_read_cfg '/etc/eibga.conf' => %eibgaconf;
}

select((select(FILE_EIBLOG), $|=1)[0]);
my $select = IO::Select->new();
my $retryinfo;
my $lastplugintime;
my $eibpoll = 1;
my $eibsrc=EIBConnection::EIBAddr();
my $eibdst=EIBConnection::EIBAddr();
my $eibbuf2=EIBConnection::EIBBuffer();

while ($running) {
  my $eibcon2 = EIBConnection->EIBSocketURL($eib_url) or INFO("Cannot connect to eibd $eib_url");
  $eibcon2->EIB_Cache_Enable();
  my $busmon = $eibcon2->EIBOpenVBusmonitor_async();
  while ($eibpoll) {
    $select->add($eibcon2->EIB_Poll_FD);
    if ($select->can_read(.5)) { # EIB Packet processing 
    if ($eibpoll=$eibcon2->EIB_Poll_Complete) {
      my $msglen=$eibcon2->EIBGetBusmonitorPacket($eibbuf2);
      if ($msglen>1) { 
    	 my %msg = decode_vbusmonitor($$eibbuf2);
...

       # Log it
       print FILE_EIBLOG getISODateStamp.",$msg{'apci'},$msg{'src'},$msg{'dst'},$msg{'data'},$msg{'value'}"
        .",$eibgaconf{$msg{'dst'}}{'DPT_SubTypeName'},$eibgaconf{$msg{'dst'}}{'DPTSubId'},$msg{'repeated'}"
        .",$msg{'class'},$msg{'rcount'},$msg{'tpdu_type'},$msg{'sequence'}\n" if($wg_config{''}{'eib_logging'});
...
}
}
