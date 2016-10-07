#!/usr/bin/perl -w 
use strict; 
use XML::LibXML; 
use DB_File; 
$DB_BTREE->{'flags'} = R_DUP ; 
my $datadir = "./xml-src/"; 
my $indexdir = "./index/"; 
my $parser = new XML::LibXML; 
my %btree; 
tie %btree, 'DB_File', "$indexdir/words.index", O_RDWR|O_CREAT, 0666, $DB_BTREE,
     or die "Cannot open $indexdir/words.index: $!\n"; 

opendir my $dir, $datadir; 
while (my $file = readdir($dir)) { 
  next if ($file =~ /^\./); 
  my $dom = $parser->parse_file("$datadir/$file"); 
  foreach my $node ($dom->findnodes("/Synset/Word")) { 
    my ($textnode) = $node->findnodes("text()"); 
    my $lcname = lc($textnode->getData); 
    if ($textnode) { $btree{$lcname} = $file; } 
  } 
} 

