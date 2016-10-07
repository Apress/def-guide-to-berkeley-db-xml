The Perl examples as a rule do not use exception handling for brevity, but 
you should in your own code.

Remember that the 'simple' parameter is necessary as part of 
'use Sleepycat::DbXml' in order to make transactions optional. Not doing so
(and not using transactions properly) can result in segfaults.

