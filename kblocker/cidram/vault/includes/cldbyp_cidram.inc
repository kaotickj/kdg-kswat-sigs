<?php
/**
 * Search engine bypasses
 *
 * This file is an optional module for the CIDRAM package.
 * It will provide bypasses for Search enginges that gets
 * caught by cloud-blocklists.
 *
 * COPYRIGHT 2019 by David MacMathan (macmathan).
 * https://bitbucket.org/macmathan
 *
 * License: GNU/GPLv2
 *
 * Version: CLDBYP-2020.3.924
 */

/** Prevents execution from outside of CIDRAM. */
if (!defined('CIDRAM')) {
    die('[CIDRAM] This should not be accessed directly.');
}
/** Inherit trigger closure (see functions.php). */
$Bypass = $CIDRAM['Bypass'];
/** Fetch hostname. */
if (empty($CIDRAM['Hostname'])) {
    $CIDRAM['Hostname'] = $CIDRAM['DNS-Reverse']($CIDRAM['BlockInfo']['IPAddr']);
}
/** Signatures start from here. */
if(substr_count($CIDRAM['BlockInfo']['WhyReason'],'aws_cidram')) $Bypass(substr_count($CIDRAM['BlockInfo']['UA'], 'DuckDuckGo-Favicons-Bot'), 'DuckDuckGo Favicons Bot AWS Bypass.');
if(substr_count($CIDRAM['BlockInfo']['WhyReason'],'aws_cidram')) $Bypass(substr_count($CIDRAM['BlockInfo']['UA'], 'DuckDuckBot/'), 'DuckDuckBot AWS Bypass.');
if(substr_count($CIDRAM['BlockInfo']['WhyReason'],'msaz_cidram')) if(preg_match("%\.search\.msn\.com$%",$CIDRAM['Hostname'])) $Bypass(preg_match("%(?i)(?:(?:msn|adix|bing)bot\/|bingpreview)%",$CIDRAM['BlockInfo']['UA']),'BingBot MSAZ Bypass');
if(substr_count($CIDRAM['BlockInfo']['WhyReason'],'Azure')) if(preg_match("%\.search\.msn\.com$%",$CIDRAM['Hostname'])) $Bypass(preg_match("%(?i)(?:(?:msn|adix|bing)bot\/|bingpreview)%",$CIDRAM['BlockInfo']['UA']),'BingBot Azure Bypass');
