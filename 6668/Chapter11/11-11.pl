use Sleepycat::DbXml 'simple';
use strict;

my $mgr = new XmlManager();
my $query = "collection('test.dbxml')/person[name='Fred']";
my $subquery = "/person/phone";

my $container = $mgr->openContainer("test.dbxml");
my $qcontext = $mgr->createQueryContext();
my $phoneqcontext = $mgr->createQueryContext();

my $results = $mgr->query($query, $qcontext);
my $phonequery = $mgr->prepare($subquery, $phoneqcontext);

my $value = new XmlValue();
my $phonevalue = new XmlValue();
while ($results->next($value)) {
    my $phoneresults = $phonequery->execute($value, $phoneqcontext);
    while ($phoneresults->next($phonevalue)) { 
        print $phonevalue->asString() . "\n";
    }
}

