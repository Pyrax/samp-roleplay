



<!DOCTYPE html>
<html lang="en" class="">
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# object: http://ogp.me/ns/object# article: http://ogp.me/ns/article# profile: http://ogp.me/ns/profile#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta http-equiv="Content-Language" content="en">
    
    
    <title>SAMPRacing/pawndoc.xsl at master · GRGServer/SAMPRacing</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub">
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub">
    <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-114.png">
    <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114.png">
    <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-144.png">
    <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144.png">
    <meta property="fb:app_id" content="1401488693436528">

      <meta content="@github" name="twitter:site" /><meta content="summary" name="twitter:card" /><meta content="GRGServer/SAMPRacing" name="twitter:title" /><meta content="SAMPRacing - The new SA-MP racing server (Grand Racing Game)" name="twitter:description" /><meta content="https://avatars3.githubusercontent.com/u/5667361?v=2&amp;s=400" name="twitter:image:src" />
<meta content="GitHub" property="og:site_name" /><meta content="object" property="og:type" /><meta content="https://avatars3.githubusercontent.com/u/5667361?v=2&amp;s=400" property="og:image" /><meta content="GRGServer/SAMPRacing" property="og:title" /><meta content="https://github.com/GRGServer/SAMPRacing" property="og:url" /><meta content="SAMPRacing - The new SA-MP racing server (Grand Racing Game)" property="og:description" />

      <meta name="browser-stats-url" content="/_stats">
    <link rel="assets" href="https://assets-cdn.github.com/">
    <link rel="conduit-xhr" href="https://ghconduit.com:25035">
    <link rel="xhr-socket" href="/_sockets">

    <meta name="msapplication-TileImage" content="/windows-tile.png">
    <meta name="msapplication-TileColor" content="#ffffff">
    <meta name="selected-link" value="repo_source" data-pjax-transient>
      <meta name="google-analytics" content="UA-3769691-2">

    <meta content="collector.githubapp.com" name="octolytics-host" /><meta content="collector-cdn.github.com" name="octolytics-script-host" /><meta content="github" name="octolytics-app-id" /><meta content="4FCFC3A7:76FB:3643129:54143E3C" name="octolytics-dimension-request_id" /><meta content="4885581" name="octolytics-actor-id" /><meta content="Pyrax" name="octolytics-actor-login" /><meta content="5d6185f5820229622c23ad49f82301c6625362cfe34fb6d104530ea425cdbc6b" name="octolytics-actor-hash" />
    <meta content="Rails, view, blob#show" name="analytics-event" />

    
    
    <link rel="icon" type="image/x-icon" href="https://assets-cdn.github.com/favicon.ico">


    <meta content="authenticity_token" name="csrf-param" />
<meta content="WYaoeGObbLGeFAcnpMQVDrQLX+WBCHVMZ9pOmyefTivpwnFmjxW9zcN+cdb9fH7LBMN71SGIDQCTucy5LRMf2g==" name="csrf-token" />

    <link href="https://assets-cdn.github.com/assets/github-49c9bbf9f4590464685eb8116415c480ddf8af23.css" media="all" rel="stylesheet" type="text/css" />
    <link href="https://assets-cdn.github.com/assets/github2-567b17c7ed8d557f1d161e3b96b366310b9638b0.css" media="all" rel="stylesheet" type="text/css" />
    


    <meta http-equiv="x-pjax-version" content="f559fa320d3ac556592cf9ab60ec6060">

      
  <meta name="description" content="SAMPRacing - The new SA-MP racing server (Grand Racing Game)">
  <meta name="go-import" content="github.com/GRGServer/SAMPRacing git https://github.com/GRGServer/SAMPRacing.git">

  <meta content="5667361" name="octolytics-dimension-user_id" /><meta content="GRGServer" name="octolytics-dimension-user_login" /><meta content="16925945" name="octolytics-dimension-repository_id" /><meta content="GRGServer/SAMPRacing" name="octolytics-dimension-repository_nwo" /><meta content="true" name="octolytics-dimension-repository_public" /><meta content="false" name="octolytics-dimension-repository_is_fork" /><meta content="16925945" name="octolytics-dimension-repository_network_root_id" /><meta content="GRGServer/SAMPRacing" name="octolytics-dimension-repository_network_root_nwo" />
  <link href="https://github.com/GRGServer/SAMPRacing/commits/master.atom" rel="alternate" title="Recent Commits to SAMPRacing:master" type="application/atom+xml">

  </head>


  <body class="logged_in  env-production windows vis-public page-blob">
    <a href="#start-of-content" tabindex="1" class="accessibility-aid js-skip-to-content">Skip to content</a>
    <div class="wrapper">
      
      
      
      


      <div class="header header-logged-in true">
  <div class="container clearfix">

    <a class="header-logo-invertocat" href="https://github.com/" aria-label="Homepage" ga-data-click="Header, go to dashboard, icon:logo">
  <span class="mega-octicon octicon-mark-github"></span>
</a>


      <div class="site-search repo-scope js-site-search">
          <form accept-charset="UTF-8" action="/GRGServer/SAMPRacing/search" class="js-site-search-form" data-global-search-url="/search" data-repo-search-url="/GRGServer/SAMPRacing/search" method="get"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /></div>
  <input type="text"
    class="js-site-search-field is-clearable"
    data-hotkey="s"
    name="q"
    placeholder="Search"
    data-global-scope-placeholder="Search GitHub"
    data-repo-scope-placeholder="Search"
    tabindex="1"
    autocapitalize="off">
  <div class="scope-badge">This repository</div>
</form>
      </div>
      <ul class="header-nav left">
        <li class="header-nav-item explore">
          <a class="header-nav-link" href="/explore" data-ga-click="Header, go to explore, text:explore">Explore</a>
        </li>
          <li class="header-nav-item">
            <a class="header-nav-link" href="https://gist.github.com" data-ga-click="Header, go to gist, text:gist">Gist</a>
          </li>
          <li class="header-nav-item">
            <a class="header-nav-link" href="/blog" data-ga-click="Header, go to blog, text:blog">Blog</a>
          </li>
        <li class="header-nav-item">
          <a class="header-nav-link" href="https://help.github.com" data-ga-click="Header, go to help, text:help">Help</a>
        </li>
      </ul>

    
<ul class="header-nav user-nav right" id="user-links">
  <li class="header-nav-item dropdown js-menu-container">
    <a class="header-nav-link name" href="/Pyrax" data-ga-click="Header, go to profile, text:username">
      <img alt="Pyrax" class="avatar" data-user="4885581" height="20" src="https://avatars0.githubusercontent.com/u/4885581?v=2&amp;s=40" width="20" />
      <span class="css-truncate">
        <span class="css-truncate-target">Pyrax</span>
      </span>
    </a>
  </li>

  <li class="header-nav-item dropdown js-menu-container">
    <a class="header-nav-link js-menu-target tooltipped tooltipped-s" href="#" aria-label="Create new..." data-ga-click="Header, create new, icon:add">
      <span class="octicon octicon-plus"></span>
      <span class="dropdown-caret"></span>
    </a>

    <div class="dropdown-menu-content js-menu-content">
      
<ul class="dropdown-menu">
  <li>
    <a href="/new"><span class="octicon octicon-repo"></span> New repository</a>
  </li>
  <li>
    <a href="/organizations/new"><span class="octicon octicon-organization"></span> New organization</a>
  </li>


    <li class="dropdown-divider"></li>
    <li class="dropdown-header">
      <span title="GRGServer/SAMPRacing">This repository</span>
    </li>
      <li>
        <a href="/GRGServer/SAMPRacing/issues/new"><span class="octicon octicon-issue-opened"></span> New issue</a>
      </li>
</ul>

    </div>
  </li>

  <li class="header-nav-item">
        <a href="/notifications" aria-label="You have no unread notifications" class="header-nav-link notification-indicator tooltipped tooltipped-s" data-ga-click="Header, go to notifications, icon:read" data-hotkey="g n">
        <span class="mail-status all-read"></span>
        <span class="octicon octicon-inbox"></span>
</a>
  </li>

  <li class="header-nav-item">
    <a class="header-nav-link tooltipped tooltipped-s" href="/settings/profile" id="account_settings" aria-label="Settings" data-ga-click="Header, go to settings, icon:settings">
      <span class="octicon octicon-gear"></span>
    </a>
  </li>

  <li class="header-nav-item">
    <form accept-charset="UTF-8" action="/logout" class="logout-form" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="aVPQF4JhUHuY/sluyor+RTyUhU0Cjz+TKmGwjV5WaMenNuvxw1B98vh/QHpU8/jxxBLRX3af+K/RZ+aYwUrgvw==" /></div>
      <button class="header-nav-link sign-out-button tooltipped tooltipped-s" aria-label="Sign out" data-ga-click="Header, sign out, icon:logout">
        <span class="octicon octicon-sign-out"></span>
      </button>
</form>  </li>

</ul>


    
  </div>
</div>

      

        


      <div id="start-of-content" class="accessibility-aid"></div>
          <div class="site" itemscope itemtype="http://schema.org/WebPage">
    <div id="js-flash-container">
      
    </div>
    <div class="pagehead repohead instapaper_ignore readability-menu">
      <div class="container">
        
<ul class="pagehead-actions">

    <li class="subscription">
      <form accept-charset="UTF-8" action="/notifications/subscribe" class="js-social-container" data-autosubmit="true" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="csPTgOIi3UAjlYhI6kyjscDIEHNy91F89C31pOpYLsoa2OF2/wEa+UzIPPYpGa5JMdDUvApCxpmSBXeglBfo1Q==" /></div>  <input id="repository_id" name="repository_id" type="hidden" value="16925945" />

    <div class="select-menu js-menu-container js-select-menu">
      <a class="social-count js-social-count" href="/GRGServer/SAMPRacing/watchers">
        3
      </a>
      <a href="/GRGServer/SAMPRacing/subscription"
        class="minibutton select-menu-button with-count js-menu-target" role="button" tabindex="0" aria-haspopup="true">
        <span class="js-select-button">
          <span class="octicon octicon-eye"></span>
          Watch
        </span>
      </a>

      <div class="select-menu-modal-holder">
        <div class="select-menu-modal subscription-menu-modal js-menu-content" aria-hidden="true">
          <div class="select-menu-header">
            <span class="select-menu-title">Notifications</span>
            <span class="octicon octicon-x js-menu-close" role="button" aria-label="Close"></span>
          </div> <!-- /.select-menu-header -->

          <div class="select-menu-list js-navigation-container" role="menu">

            <div class="select-menu-item js-navigation-item selected" role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input checked="checked" id="do_included" name="do" type="radio" value="included" />
                <h4>Not watching</h4>
                <span class="description">Be notified when participating or @mentioned.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-eye"></span>
                  Watch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input id="do_subscribed" name="do" type="radio" value="subscribed" />
                <h4>Watching</h4>
                <span class="description">Be notified of all conversations.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-eye"></span>
                  Unwatch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input id="do_ignore" name="do" type="radio" value="ignore" />
                <h4>Ignoring</h4>
                <span class="description">Never be notified.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-mute"></span>
                  Stop ignoring
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

          </div> <!-- /.select-menu-list -->

        </div> <!-- /.select-menu-modal -->
      </div> <!-- /.select-menu-modal-holder -->
    </div> <!-- /.select-menu -->

</form>
    </li>

  <li>
    
  <div class="js-toggler-container js-social-container starring-container on">

    <form accept-charset="UTF-8" action="/GRGServer/SAMPRacing/unstar" class="js-toggler-form starred js-unstar-button" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="UKwoOSS9pq9rgNpS9uedhUCKf1HSWAlGUDf9Y7c3C0olK4wrGeOzxbqUXTD0XOUaN9zWvndVKnXBoVqwKaewRg==" /></div>
      <button
        class="minibutton with-count js-toggler-target star-button"
        aria-label="Unstar this repository" title="Unstar GRGServer/SAMPRacing">
        <span class="octicon octicon-star"></span>
        Unstar
      </button>
        <a class="social-count js-social-count" href="/GRGServer/SAMPRacing/stargazers">
          3
        </a>
</form>
    <form accept-charset="UTF-8" action="/GRGServer/SAMPRacing/star" class="js-toggler-form unstarred js-star-button" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /><input name="authenticity_token" type="hidden" value="Cch6qtFjyEPJumZYha+TbYKtk1nrzr+2HeeKp9KQ5krmemOW8K9NQTRvtMAd0fWShDKFIVTE6PHuiJz/Pvz9+g==" /></div>
      <button
        class="minibutton with-count js-toggler-target star-button"
        aria-label="Star this repository" title="Star GRGServer/SAMPRacing">
        <span class="octicon octicon-star"></span>
        Star
      </button>
        <a class="social-count js-social-count" href="/GRGServer/SAMPRacing/stargazers">
          3
        </a>
</form>  </div>

  </li>


        <li>
          <a href="/GRGServer/SAMPRacing/fork" class="minibutton with-count js-toggler-target fork-button tooltipped-n" title="Fork your own copy of GRGServer/SAMPRacing to your account" aria-label="Fork your own copy of GRGServer/SAMPRacing to your account" rel="nofollow" data-method="post">
            <span class="octicon octicon-repo-forked"></span>
            Fork
          </a>
          <a href="/GRGServer/SAMPRacing/network" class="social-count">0</a>
        </li>

</ul>

        <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title public">
          <span class="mega-octicon octicon-repo"></span>
          <span class="author"><a href="/GRGServer" class="url fn" itemprop="url" rel="author"><span itemprop="title">GRGServer</span></a></span><!--
       --><span class="path-divider">/</span><!--
       --><strong><a href="/GRGServer/SAMPRacing" class="js-current-repository js-repo-home-link">SAMPRacing</a></strong>

          <span class="page-context-loader">
            <img alt="" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
          </span>

        </h1>
      </div><!-- /.container -->
    </div><!-- /.repohead -->

    <div class="container">
      <div class="repository-with-sidebar repo-container new-discussion-timeline  ">
        <div class="repository-sidebar clearfix">
            
<div class="sunken-menu vertical-right repo-nav js-repo-nav js-repository-container-pjax js-octicon-loaders" data-issue-count-url="/GRGServer/SAMPRacing/issues/counts">
  <div class="sunken-menu-contents">
    <ul class="sunken-menu-group">
      <li class="tooltipped tooltipped-w" aria-label="Code">
        <a href="/GRGServer/SAMPRacing" aria-label="Code" class="selected js-selected-navigation-item sunken-menu-item" data-hotkey="g c" data-pjax="true" data-selected-links="repo_source repo_downloads repo_commits repo_releases repo_tags repo_branches /GRGServer/SAMPRacing">
          <span class="octicon octicon-code"></span> <span class="full-word">Code</span>
          <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

        <li class="tooltipped tooltipped-w" aria-label="Issues">
          <a href="/GRGServer/SAMPRacing/issues" aria-label="Issues" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-hotkey="g i" data-selected-links="repo_issues repo_labels repo_milestones /GRGServer/SAMPRacing/issues">
            <span class="octicon octicon-issue-opened"></span> <span class="full-word">Issues</span>
            <span class="js-issue-replace-counter"></span>
            <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>        </li>

      <li class="tooltipped tooltipped-w" aria-label="Pull Requests">
        <a href="/GRGServer/SAMPRacing/pulls" aria-label="Pull Requests" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-hotkey="g p" data-selected-links="repo_pulls /GRGServer/SAMPRacing/pulls">
            <span class="octicon octicon-git-pull-request"></span> <span class="full-word">Pull Requests</span>
            <span class="js-pull-replace-counter"></span>
            <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>


    </ul>
    <div class="sunken-menu-separator"></div>
    <ul class="sunken-menu-group">

      <li class="tooltipped tooltipped-w" aria-label="Pulse">
        <a href="/GRGServer/SAMPRacing/pulse/weekly" aria-label="Pulse" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="pulse /GRGServer/SAMPRacing/pulse/weekly">
          <span class="octicon octicon-pulse"></span> <span class="full-word">Pulse</span>
          <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

      <li class="tooltipped tooltipped-w" aria-label="Graphs">
        <a href="/GRGServer/SAMPRacing/graphs" aria-label="Graphs" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="repo_graphs repo_contributors /GRGServer/SAMPRacing/graphs">
          <span class="octicon octicon-graph"></span> <span class="full-word">Graphs</span>
          <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>
    </ul>


  </div>
</div>

              <div class="only-with-full-nav">
                
  
<div class="clone-url open"
  data-protocol-type="http"
  data-url="/users/set_protocol?protocol_selector=http&amp;protocol_type=clone">
  <h3><span class="text-emphasized">HTTPS</span> clone URL</h3>
  <div class="input-group">
    <input type="text" class="input-mini input-monospace js-url-field"
           value="https://github.com/GRGServer/SAMPRacing.git" readonly="readonly">
    <span class="input-group-button">
      <button aria-label="Copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="https://github.com/GRGServer/SAMPRacing.git" data-copied-hint="Copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </span>
  </div>
</div>

  
<div class="clone-url "
  data-protocol-type="ssh"
  data-url="/users/set_protocol?protocol_selector=ssh&amp;protocol_type=clone">
  <h3><span class="text-emphasized">SSH</span> clone URL</h3>
  <div class="input-group">
    <input type="text" class="input-mini input-monospace js-url-field"
           value="git@github.com:GRGServer/SAMPRacing.git" readonly="readonly">
    <span class="input-group-button">
      <button aria-label="Copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="git@github.com:GRGServer/SAMPRacing.git" data-copied-hint="Copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </span>
  </div>
</div>

  
<div class="clone-url "
  data-protocol-type="subversion"
  data-url="/users/set_protocol?protocol_selector=subversion&amp;protocol_type=clone">
  <h3><span class="text-emphasized">Subversion</span> checkout URL</h3>
  <div class="input-group">
    <input type="text" class="input-mini input-monospace js-url-field"
           value="https://github.com/GRGServer/SAMPRacing" readonly="readonly">
    <span class="input-group-button">
      <button aria-label="Copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="https://github.com/GRGServer/SAMPRacing" data-copied-hint="Copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </span>
  </div>
</div>


<p class="clone-options">You can clone with
      <a href="#" class="js-clone-selector" data-protocol="http">HTTPS</a>,
      <a href="#" class="js-clone-selector" data-protocol="ssh">SSH</a>,
      or <a href="#" class="js-clone-selector" data-protocol="subversion">Subversion</a>.
  <a href="https://help.github.com/articles/which-remote-url-should-i-use" class="help tooltipped tooltipped-n" aria-label="Get help on which URL is right for you.">
    <span class="octicon octicon-question"></span>
  </a>
</p>


  <a href="github-windows://openRepo/https://github.com/GRGServer/SAMPRacing" class="minibutton sidebar-button" title="Save GRGServer/SAMPRacing to your computer and use it in GitHub Desktop." aria-label="Save GRGServer/SAMPRacing to your computer and use it in GitHub Desktop.">
    <span class="octicon octicon-device-desktop"></span>
    Clone in Desktop
  </a>

                <a href="/GRGServer/SAMPRacing/archive/master.zip"
                   class="minibutton sidebar-button"
                   aria-label="Download the contents of GRGServer/SAMPRacing as a zip file"
                   title="Download the contents of GRGServer/SAMPRacing as a zip file"
                   rel="nofollow">
                  <span class="octicon octicon-cloud-download"></span>
                  Download ZIP
                </a>
              </div>
        </div><!-- /.repository-sidebar -->

        <div id="js-repo-pjax-container" class="repository-content context-loader-container" data-pjax-container>
          

<a href="/GRGServer/SAMPRacing/blob/a65ab3576e2805a503cfc29c2cdc3813fd2562c3/tools/pawn/pawndoc.xsl" class="hidden js-permalink-shortcut" data-hotkey="y">Permalink</a>

<!-- blob contrib key: blob_contributors:v21:3bc8d0bbe37c3eb6795844dd464be742 -->

<div class="file-navigation">
  
<div class="select-menu js-menu-container js-select-menu left">
  <span class="minibutton select-menu-button js-menu-target css-truncate" data-hotkey="w"
    data-master-branch="master"
    data-ref="master"
    title="master"
    role="button" aria-label="Switch branches or tags" tabindex="0" aria-haspopup="true">
    <span class="octicon octicon-git-branch"></span>
    <i>branch:</i>
    <span class="js-select-button css-truncate-target">master</span>
  </span>

  <div class="select-menu-modal-holder js-menu-content js-navigation-container" data-pjax aria-hidden="true">

    <div class="select-menu-modal">
      <div class="select-menu-header">
        <span class="select-menu-title">Switch branches/tags</span>
        <span class="octicon octicon-x js-menu-close" role="button" aria-label="Close"></span>
      </div> <!-- /.select-menu-header -->

      <div class="select-menu-filters">
        <div class="select-menu-text-filter">
          <input type="text" aria-label="Filter branches/tags" id="context-commitish-filter-field" class="js-filterable-field js-navigation-enable" placeholder="Filter branches/tags">
        </div>
        <div class="select-menu-tabs">
          <ul>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="branches" class="js-select-menu-tab">Branches</a>
            </li>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="tags" class="js-select-menu-tab">Tags</a>
            </li>
          </ul>
        </div><!-- /.select-menu-tabs -->
      </div><!-- /.select-menu-filters -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="branches">

        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


            <div class="select-menu-item js-navigation-item selected">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/GRGServer/SAMPRacing/blob/master/tools/pawn/pawndoc.xsl"
                 data-name="master"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="master">master</a>
            </div> <!-- /.select-menu-item -->
        </div>

          <div class="select-menu-no-results">Nothing to show</div>
      </div> <!-- /.select-menu-list -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="tags">
        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


        </div>

        <div class="select-menu-no-results">Nothing to show</div>
      </div> <!-- /.select-menu-list -->

    </div> <!-- /.select-menu-modal -->
  </div> <!-- /.select-menu-modal-holder -->
</div> <!-- /.select-menu -->

  <div class="button-group right">
    <a href="/GRGServer/SAMPRacing/find/master"
          class="js-show-file-finder minibutton empty-icon tooltipped tooltipped-s"
          data-pjax
          data-hotkey="t"
          aria-label="Quickly jump between files">
      <span class="octicon octicon-list-unordered"></span>
    </a>
    <button class="js-zeroclipboard minibutton zeroclipboard-button"
          data-clipboard-text="tools/pawn/pawndoc.xsl"
          aria-label="Copy to clipboard"
          data-copied-hint="Copied!">
      <span class="octicon octicon-clippy"></span>
    </button>
  </div>

  <div class="breadcrumb">
    <span class='repo-root js-repo-root'><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/GRGServer/SAMPRacing" class="" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">SAMPRacing</span></a></span></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/GRGServer/SAMPRacing/tree/master/tools" class="" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">tools</span></a></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/GRGServer/SAMPRacing/tree/master/tools/pawn" class="" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">pawn</span></a></span><span class="separator"> / </span><strong class="final-path">pawndoc.xsl</strong>
  </div>
</div>


  <div class="commit commit-loader file-history-tease js-deferred-content" data-url="/GRGServer/SAMPRacing/contributors/master/tools/pawn/pawndoc.xsl">
    <div class="file-history-tease-header">
      Fetching contributors&hellip;
    </div>

    <div class="participation">
      <p class="loader-loading"><img alt="" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32-EAF2F5.gif" width="16" /></p>
      <p class="loader-error">Cannot retrieve contributors at this time</p>
    </div>
  </div>

<div class="file-box">
  <div class="file">
    <div class="meta clearfix">
      <div class="info file-name">
          <span>309 lines (277 sloc)</span>
          <span class="meta-divider"></span>
        <span>11.611 kb</span>
      </div>
      <div class="actions">
        <div class="button-group">
          <a href="/GRGServer/SAMPRacing/raw/master/tools/pawn/pawndoc.xsl" class="minibutton " id="raw-url">Raw</a>
            <a href="/GRGServer/SAMPRacing/blame/master/tools/pawn/pawndoc.xsl" class="minibutton js-update-url-with-hash">Blame</a>
          <a href="/GRGServer/SAMPRacing/commits/master/tools/pawn/pawndoc.xsl" class="minibutton " rel="nofollow">History</a>
        </div><!-- /.button-group -->

          <a class="octicon-button tooltipped tooltipped-nw"
             href="github-windows://openRepo/https://github.com/GRGServer/SAMPRacing?branch=master&amp;filepath=tools%2Fpawn%2Fpawndoc.xsl" aria-label="Open this file in GitHub for Windows">
              <span class="octicon octicon-device-desktop"></span>
          </a>

              <a class="octicon-button tooltipped tooltipped-n js-update-url-with-hash"
                 aria-label="Clicking this button will fork this project so you can edit the file"
                 href="/GRGServer/SAMPRacing/edit/master/tools/pawn/pawndoc.xsl"
                 data-method="post" rel="nofollow"><span class="octicon octicon-pencil"></span></a>

            <a class="octicon-button danger tooltipped tooltipped-s"
               href="/GRGServer/SAMPRacing/delete/master/tools/pawn/pawndoc.xsl"
               aria-label="Fork this project and delete file"
               data-method="post" data-test-id="delete-blob-file" rel="nofollow">
          <span class="octicon octicon-trashcan"></span>
        </a>
      </div><!-- /.actions -->
    </div>
    
  <div class="blob-wrapper data type-xslt">
      <table class="highlight tab-size-8 js-file-line-container">
      <tr>
        <td id="L1" class="blob-num js-line-number" data-line-number="1"></td>
        <td id="LC1" class="blob-code js-file-line"><span class="cp">&lt;?xml version=&quot;1.0&quot; ?&gt;</span></td>
      </tr>
      <tr>
        <td id="L2" class="blob-num js-line-number" data-line-number="2"></td>
        <td id="LC2" class="blob-code js-file-line"><span class="k">&lt;xsl:stylesheet</span> <span class="na">xmlns:xsl=</span><span class="s">&quot;http://www.w3.org/1999/XSL/Transform&quot;</span> <span class="na">version=</span><span class="s">&quot;1.0&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L3" class="blob-num js-line-number" data-line-number="3"></td>
        <td id="LC3" class="blob-code js-file-line"><span class="c">&lt;!-- Version: $Id: pawndoc.xsl 4258 2010-06-17 10:21:31Z thiadmer $ --&gt;</span></td>
      </tr>
      <tr>
        <td id="L4" class="blob-num js-line-number" data-line-number="4"></td>
        <td id="LC4" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L5" class="blob-num js-line-number" data-line-number="5"></td>
        <td id="LC5" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;/&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L6" class="blob-num js-line-number" data-line-number="6"></td>
        <td id="LC6" class="blob-code js-file-line"><span class="nt">&lt;HTML&gt;</span></td>
      </tr>
      <tr>
        <td id="L7" class="blob-num js-line-number" data-line-number="7"></td>
        <td id="LC7" class="blob-code js-file-line"><span class="nt">&lt;HEAD&gt;</span></td>
      </tr>
      <tr>
        <td id="L8" class="blob-num js-line-number" data-line-number="8"></td>
        <td id="LC8" class="blob-code js-file-line"><span class="nt">&lt;META</span> <span class="na">http-equiv=</span><span class="s">&quot;Content-Type&quot;</span> <span class="na">content=</span><span class="s">&quot;text/html; charset=UTF-8&quot;</span> <span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L9" class="blob-num js-line-number" data-line-number="9"></td>
        <td id="LC9" class="blob-code js-file-line"><span class="nt">&lt;TITLE&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;doc/assembly/name&quot;</span><span class="nt">/&gt;&lt;/TITLE&gt;</span></td>
      </tr>
      <tr>
        <td id="L10" class="blob-num js-line-number" data-line-number="10"></td>
        <td id="LC10" class="blob-code js-file-line"><span class="nt">&lt;STYLE</span> <span class="na">type=</span><span class="s">&quot;text/css&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L11" class="blob-num js-line-number" data-line-number="11"></td>
        <td id="LC11" class="blob-code js-file-line">	BODY { FONT-FAMILY: &quot;Verdana&quot;, sans-serif; FONT-SIZE: x-small; }</td>
      </tr>
      <tr>
        <td id="L12" class="blob-num js-line-number" data-line-number="12"></td>
        <td id="LC12" class="blob-code js-file-line">	CODE { FONT-SIZE: x-small; }</td>
      </tr>
      <tr>
        <td id="L13" class="blob-num js-line-number" data-line-number="13"></td>
        <td id="LC13" class="blob-code js-file-line">	DL { MARGIN-LEFT: 4em; DISPLAY: compact }</td>
      </tr>
      <tr>
        <td id="L14" class="blob-num js-line-number" data-line-number="14"></td>
        <td id="LC14" class="blob-code js-file-line">	DT { FONT-WEIGHT: bold }</td>
      </tr>
      <tr>
        <td id="L15" class="blob-num js-line-number" data-line-number="15"></td>
        <td id="LC15" class="blob-code js-file-line">	A:link { COLOR: #4e4887 }</td>
      </tr>
      <tr>
        <td id="L16" class="blob-num js-line-number" data-line-number="16"></td>
        <td id="LC16" class="blob-code js-file-line">	A:visited { COLOR: #8080c8 }</td>
      </tr>
      <tr>
        <td id="L17" class="blob-num js-line-number" data-line-number="17"></td>
        <td id="LC17" class="blob-code js-file-line">	A:active { COLOR: #f16043 }</td>
      </tr>
      <tr>
        <td id="L18" class="blob-num js-line-number" data-line-number="18"></td>
        <td id="LC18" class="blob-code js-file-line">	A:hover { COLOR: #f16043 }</td>
      </tr>
      <tr>
        <td id="L19" class="blob-num js-line-number" data-line-number="19"></td>
        <td id="LC19" class="blob-code js-file-line">	P { MARGIN-BOTTOM: 0.5em; MARGIN-TOP: 0.5em; MARGIN-LEFT: 4em }</td>
      </tr>
      <tr>
        <td id="L20" class="blob-num js-line-number" data-line-number="20"></td>
        <td id="LC20" class="blob-code js-file-line">	P.noindent { MARGIN-LEFT: 0em }</td>
      </tr>
      <tr>
        <td id="L21" class="blob-num js-line-number" data-line-number="21"></td>
        <td id="LC21" class="blob-code js-file-line">	P.syntax { FONT-WEIGHT: bold }</td>
      </tr>
      <tr>
        <td id="L22" class="blob-num js-line-number" data-line-number="22"></td>
        <td id="LC22" class="blob-code js-file-line">	HR.para { HEIGHT: 0; BORDER: 0; COLOR: white; BACKGROUND-COLOR: transparent; MARGIN-TOP: 0.5em; MARGIN-BOTTOM: 0; }</td>
      </tr>
      <tr>
        <td id="L23" class="blob-num js-line-number" data-line-number="23"></td>
        <td id="LC23" class="blob-code js-file-line">	XMP { BACKGROUND-COLOR: #ddeeff; FONT-SIZE: x-small; MARGIN: 1em }</td>
      </tr>
      <tr>
        <td id="L24" class="blob-num js-line-number" data-line-number="24"></td>
        <td id="LC24" class="blob-code js-file-line">	PRE { BACKGROUND-COLOR: #ddeeff; FONT-SIZE: x-small; MARGIN: 1em }</td>
      </tr>
      <tr>
        <td id="L25" class="blob-num js-line-number" data-line-number="25"></td>
        <td id="LC25" class="blob-code js-file-line">	TABLE { BORDER-BOTTOM: medium none; BORDER-LEFT: medium none; BORDER-RIGHT: medium none; BORDER-TOP: medium none }</td>
      </tr>
      <tr>
        <td id="L26" class="blob-num js-line-number" data-line-number="26"></td>
        <td id="LC26" class="blob-code js-file-line">	TABLE.param { BACKGROUND-COLOR: #ddeeff; }</td>
      </tr>
      <tr>
        <td id="L27" class="blob-num js-line-number" data-line-number="27"></td>
        <td id="LC27" class="blob-code js-file-line">	TABLE.transition { BACKGROUND-COLOR: #ddeeff; }</td>
      </tr>
      <tr>
        <td id="L28" class="blob-num js-line-number" data-line-number="28"></td>
        <td id="LC28" class="blob-code js-file-line">	TD { BACKGROUND-COLOR: #ddeeff; BORDER-BOTTOM: medium none; BORDER-LEFT: medium none; BORDER-RIGHT: medium none; BORDER-TOP: medium none; FONT-SIZE: x-small; MARGIN: 2px; PADDING-BOTTOM: 2px; PADDING-LEFT: 2px; PADDING-RIGHT: 2px; PADDING-TOP: 2px; TEXT-ALIGN: left }</td>
      </tr>
      <tr>
        <td id="L29" class="blob-num js-line-number" data-line-number="29"></td>
        <td id="LC29" class="blob-code js-file-line">	TD.header { BACKGROUND-COLOR: transparent; FONT-WEIGHT: bold; COLOR: #4e4887; WIDTH: 3.3em; PADDING-LEFT: 0px; MARGIN-BOTTOM: 0.5em }</td>
      </tr>
      <tr>
        <td id="L30" class="blob-num js-line-number" data-line-number="30"></td>
        <td id="LC30" class="blob-code js-file-line">	TD.inline { BACKGROUND-COLOR: transparent }</td>
      </tr>
      <tr>
        <td id="L31" class="blob-num js-line-number" data-line-number="31"></td>
        <td id="LC31" class="blob-code js-file-line">	TD.param { FONT-WEIGHT: bold; FONT-STYLE: italic; PADDING-RIGHT: 20px; }</td>
      </tr>
      <tr>
        <td id="L32" class="blob-num js-line-number" data-line-number="32"></td>
        <td id="LC32" class="blob-code js-file-line">	TD.transition { PADDING-RIGHT: 10px; }</td>
      </tr>
      <tr>
        <td id="L33" class="blob-num js-line-number" data-line-number="33"></td>
        <td id="LC33" class="blob-code js-file-line">	TH { BACKGROUND-COLOR: #336699; COLOR: #ddeeff; BORDER-BOTTOM: medium none; BORDER-LEFT: medium none; BORDER-RIGHT: medium none; BORDER-TOP: medium none; FONT-SIZE: x-small; MARGIN: 2px; PADDING-BOTTOM: 2px; PADDING-LEFT: 4px; PADDING-RIGHT: 4px; PADDING-TOP: 2px; TEXT-ALIGN: left }</td>
      </tr>
      <tr>
        <td id="L34" class="blob-num js-line-number" data-line-number="34"></td>
        <td id="LC34" class="blob-code js-file-line">	UL { MARGIN-TOP: 0.5em; }</td>
      </tr>
      <tr>
        <td id="L35" class="blob-num js-line-number" data-line-number="35"></td>
        <td id="LC35" class="blob-code js-file-line">	LI.referrer { DISPLAY: inline; PADDING-RIGHT: 8px }</td>
      </tr>
      <tr>
        <td id="L36" class="blob-num js-line-number" data-line-number="36"></td>
        <td id="LC36" class="blob-code js-file-line">	LI.dependency { DISPLAY: inline; PADDING-RIGHT: 8px }</td>
      </tr>
      <tr>
        <td id="L37" class="blob-num js-line-number" data-line-number="37"></td>
        <td id="LC37" class="blob-code js-file-line">	LI.seealso { DISPLAY: inline; PADDING-RIGHT: 8px }</td>
      </tr>
      <tr>
        <td id="L38" class="blob-num js-line-number" data-line-number="38"></td>
        <td id="LC38" class="blob-code js-file-line">	LI.attribute { DISPLAY: inline; PADDING-RIGHT: 8px }</td>
      </tr>
      <tr>
        <td id="L39" class="blob-num js-line-number" data-line-number="39"></td>
        <td id="LC39" class="blob-code js-file-line">	OL { MARGIN-TOP: 0.5em; }</td>
      </tr>
      <tr>
        <td id="L40" class="blob-num js-line-number" data-line-number="40"></td>
        <td id="LC40" class="blob-code js-file-line">	SPAN.paraminfo { FONT-WEIGHT:Bold; COLOR: #336699; }</td>
      </tr>
      <tr>
        <td id="L41" class="blob-num js-line-number" data-line-number="41"></td>
        <td id="LC41" class="blob-code js-file-line">	H1 { COLOR: #336699; FONT-SIZE: x-large; MARGIN-BOTTOM: 0.5em; MARGIN-TOP: 1em; PADDING-LEFT: 4px }</td>
      </tr>
      <tr>
        <td id="L42" class="blob-num js-line-number" data-line-number="42"></td>
        <td id="LC42" class="blob-code js-file-line">	H2 { BORDER-RIGHT: #4e4887 8px solid; FONT-SIZE: medium; BORDER-TOP: #4e4887 2px solid; COLOR: #4e4887; MARGIN-BOTTOM: 0.5em; MARGIN-TOP: 1em; }</td>
      </tr>
      <tr>
        <td id="L43" class="blob-num js-line-number" data-line-number="43"></td>
        <td id="LC43" class="blob-code js-file-line">	H2.general { BORDER: none; }</td>
      </tr>
      <tr>
        <td id="L44" class="blob-num js-line-number" data-line-number="44"></td>
        <td id="LC44" class="blob-code js-file-line">	H3 { COLOR: #4e4887; FONT-SIZE: x-small; MARGIN-BOTTOM: 0.5em }</td>
      </tr>
      <tr>
        <td id="L45" class="blob-num js-line-number" data-line-number="45"></td>
        <td id="LC45" class="blob-code js-file-line">	H4 { COLOR: #4e4887; FONT-SIZE: x-small; FONT-STYLE: italic; MARGIN-BOTTOM: 0.5em }</td>
      </tr>
      <tr>
        <td id="L46" class="blob-num js-line-number" data-line-number="46"></td>
        <td id="LC46" class="blob-code js-file-line">	H5 { COLOR: #4e4887; FONT-SIZE: xx-small; MARGIN-BOTTOM: 0.5em }</td>
      </tr>
      <tr>
        <td id="L47" class="blob-num js-line-number" data-line-number="47"></td>
        <td id="LC47" class="blob-code js-file-line">	H6 { COLOR: #4e4887; FONT-SIZE: xx-small; FONT-STYLE: italic; MARGIN-BOTTOM: 0.5em }</td>
      </tr>
      <tr>
        <td id="L48" class="blob-num js-line-number" data-line-number="48"></td>
        <td id="LC48" class="blob-code js-file-line"><span class="nt">&lt;/STYLE&gt;</span></td>
      </tr>
      <tr>
        <td id="L49" class="blob-num js-line-number" data-line-number="49"></td>
        <td id="LC49" class="blob-code js-file-line"><span class="nt">&lt;/HEAD&gt;</span></td>
      </tr>
      <tr>
        <td id="L50" class="blob-num js-line-number" data-line-number="50"></td>
        <td id="LC50" class="blob-code js-file-line"><span class="nt">&lt;BODY&gt;</span></td>
      </tr>
      <tr>
        <td id="L51" class="blob-num js-line-number" data-line-number="51"></td>
        <td id="LC51" class="blob-code js-file-line">	<span class="nt">&lt;h1&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;doc/assembly/name&quot;</span><span class="nt">/&gt;&lt;/h1&gt;</span></td>
      </tr>
      <tr>
        <td id="L52" class="blob-num js-line-number" data-line-number="52"></td>
        <td id="LC52" class="blob-code js-file-line">	<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;doc/general&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L53" class="blob-num js-line-number" data-line-number="53"></td>
        <td id="LC53" class="blob-code js-file-line">	<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;doc/members/member&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L54" class="blob-num js-line-number" data-line-number="54"></td>
        <td id="LC54" class="blob-code js-file-line"><span class="nt">&lt;/BODY&gt;</span></td>
      </tr>
      <tr>
        <td id="L55" class="blob-num js-line-number" data-line-number="55"></td>
        <td id="LC55" class="blob-code js-file-line"><span class="nt">&lt;/HTML&gt;</span></td>
      </tr>
      <tr>
        <td id="L56" class="blob-num js-line-number" data-line-number="56"></td>
        <td id="LC56" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L57" class="blob-num js-line-number" data-line-number="57"></td>
        <td id="LC57" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L58" class="blob-num js-line-number" data-line-number="58"></td>
        <td id="LC58" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;general&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L59" class="blob-num js-line-number" data-line-number="59"></td>
        <td id="LC59" class="blob-code js-file-line">    <span class="k">&lt;xsl:apply-templates</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L60" class="blob-num js-line-number" data-line-number="60"></td>
        <td id="LC60" class="blob-code js-file-line">    <span class="nt">&lt;br/&gt;</span></td>
      </tr>
      <tr>
        <td id="L61" class="blob-num js-line-number" data-line-number="61"></td>
        <td id="LC61" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L62" class="blob-num js-line-number" data-line-number="62"></td>
        <td id="LC62" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L63" class="blob-num js-line-number" data-line-number="63"></td>
        <td id="LC63" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;member&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L64" class="blob-num js-line-number" data-line-number="64"></td>
        <td id="LC64" class="blob-code js-file-line">	<span class="k">&lt;xsl:choose</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L65" class="blob-num js-line-number" data-line-number="65"></td>
        <td id="LC65" class="blob-code js-file-line">		<span class="k">&lt;xsl:when</span> <span class="na">test=</span><span class="s">&quot;substring(@name,1,2) = &#39;T:&#39;&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L66" class="blob-num js-line-number" data-line-number="66"></td>
        <td id="LC66" class="blob-code js-file-line">			<span class="nt">&lt;a&gt;</span><span class="k">&lt;xsl:attribute</span> <span class="na">name=</span><span class="s">&quot;name&quot;</span><span class="nt">&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;substring(@name,3)&quot;</span><span class="nt">/&gt;</span><span class="k">&lt;/xsl:attribute&gt;</span><span class="nt">&lt;h2&gt;&lt;span</span> <span class="na">style=</span><span class="s">&quot;float:right; padding-right:2px&quot;</span><span class="nt">&gt;</span>enumeration<span class="nt">&lt;/span&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;substring(@name,3)&quot;</span><span class="nt">/&gt;&lt;/h2&gt;&lt;/a&gt;</span></td>
      </tr>
      <tr>
        <td id="L67" class="blob-num js-line-number" data-line-number="67"></td>
        <td id="LC67" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;summary&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L68" class="blob-num js-line-number" data-line-number="68"></td>
        <td id="LC68" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;remarks or text()&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L69" class="blob-num js-line-number" data-line-number="69"></td>
        <td id="LC69" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>Remarks<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L70" class="blob-num js-line-number" data-line-number="70"></td>
        <td id="LC70" class="blob-code js-file-line">				<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;remarks&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L71" class="blob-num js-line-number" data-line-number="71"></td>
        <td id="LC71" class="blob-code js-file-line">				<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;text()&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L72" class="blob-num js-line-number" data-line-number="72"></td>
        <td id="LC72" class="blob-code js-file-line">  			  <span class="nt">&lt;p&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;text()&quot;</span><span class="nt">/&gt;&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L73" class="blob-num js-line-number" data-line-number="73"></td>
        <td id="LC73" class="blob-code js-file-line">  			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L74" class="blob-num js-line-number" data-line-number="74"></td>
        <td id="LC74" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L75" class="blob-num js-line-number" data-line-number="75"></td>
        <td id="LC75" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;member&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L76" class="blob-num js-line-number" data-line-number="76"></td>
        <td id="LC76" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>Members<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L77" class="blob-num js-line-number" data-line-number="77"></td>
        <td id="LC77" class="blob-code js-file-line">				<span class="nt">&lt;blockquote&gt;</span></td>
      </tr>
      <tr>
        <td id="L78" class="blob-num js-line-number" data-line-number="78"></td>
        <td id="LC78" class="blob-code js-file-line">				<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;member&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L79" class="blob-num js-line-number" data-line-number="79"></td>
        <td id="LC79" class="blob-code js-file-line">				<span class="nt">&lt;/blockquote&gt;</span></td>
      </tr>
      <tr>
        <td id="L80" class="blob-num js-line-number" data-line-number="80"></td>
        <td id="LC80" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L81" class="blob-num js-line-number" data-line-number="81"></td>
        <td id="LC81" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;example&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L82" class="blob-num js-line-number" data-line-number="82"></td>
        <td id="LC82" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;referrer&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L83" class="blob-num js-line-number" data-line-number="83"></td>
        <td id="LC83" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>Used by<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L84" class="blob-num js-line-number" data-line-number="84"></td>
        <td id="LC84" class="blob-code js-file-line">				<span class="nt">&lt;ul&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;referrer&quot;</span><span class="nt">/&gt;&lt;/ul&gt;</span></td>
      </tr>
      <tr>
        <td id="L85" class="blob-num js-line-number" data-line-number="85"></td>
        <td id="LC85" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L86" class="blob-num js-line-number" data-line-number="86"></td>
        <td id="LC86" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;dependency&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L87" class="blob-num js-line-number" data-line-number="87"></td>
        <td id="LC87" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>Depends on<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L88" class="blob-num js-line-number" data-line-number="88"></td>
        <td id="LC88" class="blob-code js-file-line">				<span class="nt">&lt;ul&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;dependency&quot;</span><span class="nt">/&gt;&lt;/ul&gt;</span></td>
      </tr>
      <tr>
        <td id="L89" class="blob-num js-line-number" data-line-number="89"></td>
        <td id="LC89" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L90" class="blob-num js-line-number" data-line-number="90"></td>
        <td id="LC90" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;location&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L91" class="blob-num js-line-number" data-line-number="91"></td>
        <td id="LC91" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;seealso&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L92" class="blob-num js-line-number" data-line-number="92"></td>
        <td id="LC92" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>See Also<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L93" class="blob-num js-line-number" data-line-number="93"></td>
        <td id="LC93" class="blob-code js-file-line">				<span class="nt">&lt;ul&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;seealso&quot;</span><span class="nt">/&gt;&lt;/ul&gt;</span></td>
      </tr>
      <tr>
        <td id="L94" class="blob-num js-line-number" data-line-number="94"></td>
        <td id="LC94" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L95" class="blob-num js-line-number" data-line-number="95"></td>
        <td id="LC95" class="blob-code js-file-line">		<span class="k">&lt;/xsl:when&gt;</span></td>
      </tr>
      <tr>
        <td id="L96" class="blob-num js-line-number" data-line-number="96"></td>
        <td id="LC96" class="blob-code js-file-line">		<span class="k">&lt;xsl:when</span> <span class="na">test=</span><span class="s">&quot;substring(@name,1,2) = &#39;C:&#39;&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L97" class="blob-num js-line-number" data-line-number="97"></td>
        <td id="LC97" class="blob-code js-file-line">			<span class="nt">&lt;a&gt;</span><span class="k">&lt;xsl:attribute</span> <span class="na">name=</span><span class="s">&quot;name&quot;</span><span class="nt">&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;substring(@name,3)&quot;</span><span class="nt">/&gt;</span><span class="k">&lt;/xsl:attribute&gt;</span><span class="nt">&lt;h2&gt;&lt;span</span> <span class="na">style=</span><span class="s">&quot;float:right; padding-right:2px&quot;</span><span class="nt">&gt;</span>constant<span class="nt">&lt;/span&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;substring(@name,3)&quot;</span><span class="nt">/&gt;&lt;/h2&gt;&lt;/a&gt;</span></td>
      </tr>
      <tr>
        <td id="L98" class="blob-num js-line-number" data-line-number="98"></td>
        <td id="LC98" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;summary&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L99" class="blob-num js-line-number" data-line-number="99"></td>
        <td id="LC99" class="blob-code js-file-line">			<span class="nt">&lt;p</span> <span class="na">class=</span><span class="s">&quot;noindent&quot;</span><span class="nt">&gt;&lt;table&gt;&lt;tr&gt;&lt;td</span> <span class="na">class=</span><span class="s">&quot;header inline&quot;</span><span class="nt">&gt;</span>Value<span class="nt">&lt;/td&gt;&lt;td</span> <span class="na">class=</span><span class="s">&quot;inline&quot;</span><span class="nt">&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@value&quot;</span><span class="nt">/&gt;&lt;/td&gt;&lt;/tr&gt;&lt;/table&gt;&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L100" class="blob-num js-line-number" data-line-number="100"></td>
        <td id="LC100" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;tagname&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L101" class="blob-num js-line-number" data-line-number="101"></td>
        <td id="LC101" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;size&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L102" class="blob-num js-line-number" data-line-number="102"></td>
        <td id="LC102" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;remarks or text()&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L103" class="blob-num js-line-number" data-line-number="103"></td>
        <td id="LC103" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>Remarks<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L104" class="blob-num js-line-number" data-line-number="104"></td>
        <td id="LC104" class="blob-code js-file-line">				<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;remarks&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L105" class="blob-num js-line-number" data-line-number="105"></td>
        <td id="LC105" class="blob-code js-file-line">				<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;text()&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L106" class="blob-num js-line-number" data-line-number="106"></td>
        <td id="LC106" class="blob-code js-file-line">				<span class="nt">&lt;p&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;text()&quot;</span><span class="nt">/&gt;&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L107" class="blob-num js-line-number" data-line-number="107"></td>
        <td id="LC107" class="blob-code js-file-line">  			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L108" class="blob-num js-line-number" data-line-number="108"></td>
        <td id="LC108" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L109" class="blob-num js-line-number" data-line-number="109"></td>
        <td id="LC109" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;example&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L110" class="blob-num js-line-number" data-line-number="110"></td>
        <td id="LC110" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;referrer&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L111" class="blob-num js-line-number" data-line-number="111"></td>
        <td id="LC111" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>Used by<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L112" class="blob-num js-line-number" data-line-number="112"></td>
        <td id="LC112" class="blob-code js-file-line">				<span class="nt">&lt;ul&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;referrer&quot;</span><span class="nt">/&gt;&lt;/ul&gt;</span></td>
      </tr>
      <tr>
        <td id="L113" class="blob-num js-line-number" data-line-number="113"></td>
        <td id="LC113" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L114" class="blob-num js-line-number" data-line-number="114"></td>
        <td id="LC114" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;dependency&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L115" class="blob-num js-line-number" data-line-number="115"></td>
        <td id="LC115" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>Depends on<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L116" class="blob-num js-line-number" data-line-number="116"></td>
        <td id="LC116" class="blob-code js-file-line">				<span class="nt">&lt;ul&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;dependency&quot;</span><span class="nt">/&gt;&lt;/ul&gt;</span></td>
      </tr>
      <tr>
        <td id="L117" class="blob-num js-line-number" data-line-number="117"></td>
        <td id="LC117" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L118" class="blob-num js-line-number" data-line-number="118"></td>
        <td id="LC118" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;location&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L119" class="blob-num js-line-number" data-line-number="119"></td>
        <td id="LC119" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;seealso&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L120" class="blob-num js-line-number" data-line-number="120"></td>
        <td id="LC120" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>See Also<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L121" class="blob-num js-line-number" data-line-number="121"></td>
        <td id="LC121" class="blob-code js-file-line">				<span class="nt">&lt;ul&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;seealso&quot;</span><span class="nt">/&gt;&lt;/ul&gt;</span></td>
      </tr>
      <tr>
        <td id="L122" class="blob-num js-line-number" data-line-number="122"></td>
        <td id="LC122" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L123" class="blob-num js-line-number" data-line-number="123"></td>
        <td id="LC123" class="blob-code js-file-line">		<span class="k">&lt;/xsl:when&gt;</span></td>
      </tr>
      <tr>
        <td id="L124" class="blob-num js-line-number" data-line-number="124"></td>
        <td id="LC124" class="blob-code js-file-line">		<span class="k">&lt;xsl:when</span> <span class="na">test=</span><span class="s">&quot;substring(@name,1,2) = &#39;M:&#39;&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L125" class="blob-num js-line-number" data-line-number="125"></td>
        <td id="LC125" class="blob-code js-file-line">			<span class="nt">&lt;a&gt;</span><span class="k">&lt;xsl:attribute</span> <span class="na">name=</span><span class="s">&quot;name&quot;</span><span class="nt">&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;substring(@name,3)&quot;</span><span class="nt">/&gt;</span><span class="k">&lt;/xsl:attribute&gt;</span><span class="nt">&lt;h2&gt;&lt;span</span> <span class="na">style=</span><span class="s">&quot;float:right; padding-right:2px&quot;</span><span class="nt">&gt;</span>function<span class="nt">&lt;/span&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;substring(@name,3)&quot;</span><span class="nt">/&gt;&lt;/h2&gt;&lt;/a&gt;</span></td>
      </tr>
      <tr>
        <td id="L126" class="blob-num js-line-number" data-line-number="126"></td>
        <td id="LC126" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;summary&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L127" class="blob-num js-line-number" data-line-number="127"></td>
        <td id="LC127" class="blob-code js-file-line">			<span class="nt">&lt;h3&gt;</span>Syntax<span class="nt">&lt;/h3&gt;&lt;p</span> <span class="na">class=</span><span class="s">&quot;syntax&quot;</span><span class="nt">&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@syntax&quot;</span><span class="nt">/&gt;&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L128" class="blob-num js-line-number" data-line-number="128"></td>
        <td id="LC128" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;param&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L129" class="blob-num js-line-number" data-line-number="129"></td>
        <td id="LC129" class="blob-code js-file-line">				<span class="nt">&lt;p&gt;&lt;table</span> <span class="na">class=</span><span class="s">&quot;param&quot;</span><span class="nt">&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;param&quot;</span><span class="nt">/&gt;&lt;/table&gt;&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L130" class="blob-num js-line-number" data-line-number="130"></td>
        <td id="LC130" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L131" class="blob-num js-line-number" data-line-number="131"></td>
        <td id="LC131" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;tagname&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L132" class="blob-num js-line-number" data-line-number="132"></td>
        <td id="LC132" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;returns&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L133" class="blob-num js-line-number" data-line-number="133"></td>
        <td id="LC133" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;remarks or text()&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L134" class="blob-num js-line-number" data-line-number="134"></td>
        <td id="LC134" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>Remarks<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L135" class="blob-num js-line-number" data-line-number="135"></td>
        <td id="LC135" class="blob-code js-file-line">				<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;remarks&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L136" class="blob-num js-line-number" data-line-number="136"></td>
        <td id="LC136" class="blob-code js-file-line">				<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;text()&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L137" class="blob-num js-line-number" data-line-number="137"></td>
        <td id="LC137" class="blob-code js-file-line">				<span class="nt">&lt;p&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;text()&quot;</span><span class="nt">/&gt;&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L138" class="blob-num js-line-number" data-line-number="138"></td>
        <td id="LC138" class="blob-code js-file-line">  			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L139" class="blob-num js-line-number" data-line-number="139"></td>
        <td id="LC139" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L140" class="blob-num js-line-number" data-line-number="140"></td>
        <td id="LC140" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;example&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L141" class="blob-num js-line-number" data-line-number="141"></td>
        <td id="LC141" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;referrer&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L142" class="blob-num js-line-number" data-line-number="142"></td>
        <td id="LC142" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>Used by<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L143" class="blob-num js-line-number" data-line-number="143"></td>
        <td id="LC143" class="blob-code js-file-line">				<span class="nt">&lt;ul&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;referrer&quot;</span><span class="nt">/&gt;&lt;/ul&gt;</span></td>
      </tr>
      <tr>
        <td id="L144" class="blob-num js-line-number" data-line-number="144"></td>
        <td id="LC144" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L145" class="blob-num js-line-number" data-line-number="145"></td>
        <td id="LC145" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;dependency&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L146" class="blob-num js-line-number" data-line-number="146"></td>
        <td id="LC146" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>Depends on<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L147" class="blob-num js-line-number" data-line-number="147"></td>
        <td id="LC147" class="blob-code js-file-line">				<span class="nt">&lt;ul&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;dependency&quot;</span><span class="nt">/&gt;&lt;/ul&gt;</span></td>
      </tr>
      <tr>
        <td id="L148" class="blob-num js-line-number" data-line-number="148"></td>
        <td id="LC148" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L149" class="blob-num js-line-number" data-line-number="149"></td>
        <td id="LC149" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;attribute&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L150" class="blob-num js-line-number" data-line-number="150"></td>
        <td id="LC150" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>Attributes<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L151" class="blob-num js-line-number" data-line-number="151"></td>
        <td id="LC151" class="blob-code js-file-line">				<span class="nt">&lt;ul&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;attribute&quot;</span><span class="nt">/&gt;&lt;/ul&gt;</span></td>
      </tr>
      <tr>
        <td id="L152" class="blob-num js-line-number" data-line-number="152"></td>
        <td id="LC152" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L153" class="blob-num js-line-number" data-line-number="153"></td>
        <td id="LC153" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;automaton&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L154" class="blob-num js-line-number" data-line-number="154"></td>
        <td id="LC154" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;transition&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L155" class="blob-num js-line-number" data-line-number="155"></td>
        <td id="LC155" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>Transition table<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L156" class="blob-num js-line-number" data-line-number="156"></td>
        <td id="LC156" class="blob-code js-file-line">				<span class="nt">&lt;p&gt;</span></td>
      </tr>
      <tr>
        <td id="L157" class="blob-num js-line-number" data-line-number="157"></td>
        <td id="LC157" class="blob-code js-file-line">					<span class="nt">&lt;table</span> <span class="na">class=</span><span class="s">&quot;transition&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L158" class="blob-num js-line-number" data-line-number="158"></td>
        <td id="LC158" class="blob-code js-file-line">						<span class="nt">&lt;tr&gt;&lt;th&gt;</span>Source<span class="nt">&lt;/th&gt;&lt;th&gt;</span>Target<span class="nt">&lt;/th&gt;&lt;th&gt;</span>Condition<span class="nt">&lt;/th&gt;&lt;/tr&gt;</span></td>
      </tr>
      <tr>
        <td id="L159" class="blob-num js-line-number" data-line-number="159"></td>
        <td id="LC159" class="blob-code js-file-line">						<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;transition&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L160" class="blob-num js-line-number" data-line-number="160"></td>
        <td id="LC160" class="blob-code js-file-line">					<span class="nt">&lt;/table&gt;</span></td>
      </tr>
      <tr>
        <td id="L161" class="blob-num js-line-number" data-line-number="161"></td>
        <td id="LC161" class="blob-code js-file-line">				<span class="nt">&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L162" class="blob-num js-line-number" data-line-number="162"></td>
        <td id="LC162" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L163" class="blob-num js-line-number" data-line-number="163"></td>
        <td id="LC163" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;location&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L164" class="blob-num js-line-number" data-line-number="164"></td>
        <td id="LC164" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;stacksize&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L165" class="blob-num js-line-number" data-line-number="165"></td>
        <td id="LC165" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;seealso&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L166" class="blob-num js-line-number" data-line-number="166"></td>
        <td id="LC166" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>See Also<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L167" class="blob-num js-line-number" data-line-number="167"></td>
        <td id="LC167" class="blob-code js-file-line">				<span class="nt">&lt;ul&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;seealso&quot;</span><span class="nt">/&gt;&lt;/ul&gt;</span></td>
      </tr>
      <tr>
        <td id="L168" class="blob-num js-line-number" data-line-number="168"></td>
        <td id="LC168" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L169" class="blob-num js-line-number" data-line-number="169"></td>
        <td id="LC169" class="blob-code js-file-line">		<span class="k">&lt;/xsl:when&gt;</span></td>
      </tr>
      <tr>
        <td id="L170" class="blob-num js-line-number" data-line-number="170"></td>
        <td id="LC170" class="blob-code js-file-line">		<span class="k">&lt;xsl:when</span> <span class="na">test=</span><span class="s">&quot;substring(@name,1,2) = &#39;F:&#39;&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L171" class="blob-num js-line-number" data-line-number="171"></td>
        <td id="LC171" class="blob-code js-file-line">			<span class="nt">&lt;a&gt;</span><span class="k">&lt;xsl:attribute</span> <span class="na">name=</span><span class="s">&quot;name&quot;</span><span class="nt">&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;substring(@name,3)&quot;</span><span class="nt">/&gt;</span><span class="k">&lt;/xsl:attribute&gt;</span><span class="nt">&lt;h2&gt;&lt;span</span> <span class="na">style=</span><span class="s">&quot;float:right; padding-right:2px&quot;</span><span class="nt">&gt;</span>variable<span class="nt">&lt;/span&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;substring(@name,3)&quot;</span><span class="nt">/&gt;&lt;/h2&gt;&lt;/a&gt;</span></td>
      </tr>
      <tr>
        <td id="L172" class="blob-num js-line-number" data-line-number="172"></td>
        <td id="LC172" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;summary&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L173" class="blob-num js-line-number" data-line-number="173"></td>
        <td id="LC173" class="blob-code js-file-line">			<span class="nt">&lt;h3&gt;</span>Syntax<span class="nt">&lt;/h3&gt;&lt;p</span> <span class="na">class=</span><span class="s">&quot;syntax&quot;</span><span class="nt">&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@syntax&quot;</span><span class="nt">/&gt;&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L174" class="blob-num js-line-number" data-line-number="174"></td>
        <td id="LC174" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;tagname&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L175" class="blob-num js-line-number" data-line-number="175"></td>
        <td id="LC175" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;remarks or text()&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L176" class="blob-num js-line-number" data-line-number="176"></td>
        <td id="LC176" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>Remarks<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L177" class="blob-num js-line-number" data-line-number="177"></td>
        <td id="LC177" class="blob-code js-file-line">				<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;remarks&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L178" class="blob-num js-line-number" data-line-number="178"></td>
        <td id="LC178" class="blob-code js-file-line">				<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;text()&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L179" class="blob-num js-line-number" data-line-number="179"></td>
        <td id="LC179" class="blob-code js-file-line">				<span class="nt">&lt;p&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;text()&quot;</span><span class="nt">/&gt;&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L180" class="blob-num js-line-number" data-line-number="180"></td>
        <td id="LC180" class="blob-code js-file-line">  			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L181" class="blob-num js-line-number" data-line-number="181"></td>
        <td id="LC181" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L182" class="blob-num js-line-number" data-line-number="182"></td>
        <td id="LC182" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;example&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L183" class="blob-num js-line-number" data-line-number="183"></td>
        <td id="LC183" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;referrer&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L184" class="blob-num js-line-number" data-line-number="184"></td>
        <td id="LC184" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>Used by<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L185" class="blob-num js-line-number" data-line-number="185"></td>
        <td id="LC185" class="blob-code js-file-line">				<span class="nt">&lt;ul&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;referrer&quot;</span><span class="nt">/&gt;&lt;/ul&gt;</span></td>
      </tr>
      <tr>
        <td id="L186" class="blob-num js-line-number" data-line-number="186"></td>
        <td id="LC186" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L187" class="blob-num js-line-number" data-line-number="187"></td>
        <td id="LC187" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;dependency&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L188" class="blob-num js-line-number" data-line-number="188"></td>
        <td id="LC188" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>Depends on<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L189" class="blob-num js-line-number" data-line-number="189"></td>
        <td id="LC189" class="blob-code js-file-line">				<span class="nt">&lt;ul&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;dependency&quot;</span><span class="nt">/&gt;&lt;/ul&gt;</span></td>
      </tr>
      <tr>
        <td id="L190" class="blob-num js-line-number" data-line-number="190"></td>
        <td id="LC190" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L191" class="blob-num js-line-number" data-line-number="191"></td>
        <td id="LC191" class="blob-code js-file-line">			<span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;location&quot;</span><span class="nt">/&gt;</span></td>
      </tr>
      <tr>
        <td id="L192" class="blob-num js-line-number" data-line-number="192"></td>
        <td id="LC192" class="blob-code js-file-line">			<span class="k">&lt;xsl:if</span> <span class="na">test=</span><span class="s">&quot;seealso&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L193" class="blob-num js-line-number" data-line-number="193"></td>
        <td id="LC193" class="blob-code js-file-line">				<span class="nt">&lt;h3&gt;</span>See Also<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L194" class="blob-num js-line-number" data-line-number="194"></td>
        <td id="LC194" class="blob-code js-file-line">				<span class="nt">&lt;ul&gt;</span><span class="k">&lt;xsl:apply-templates</span> <span class="na">select=</span><span class="s">&quot;seealso&quot;</span><span class="nt">/&gt;&lt;/ul&gt;</span></td>
      </tr>
      <tr>
        <td id="L195" class="blob-num js-line-number" data-line-number="195"></td>
        <td id="LC195" class="blob-code js-file-line">			<span class="k">&lt;/xsl:if&gt;</span></td>
      </tr>
      <tr>
        <td id="L196" class="blob-num js-line-number" data-line-number="196"></td>
        <td id="LC196" class="blob-code js-file-line">		<span class="k">&lt;/xsl:when&gt;</span></td>
      </tr>
      <tr>
        <td id="L197" class="blob-num js-line-number" data-line-number="197"></td>
        <td id="LC197" class="blob-code js-file-line">	<span class="k">&lt;/xsl:choose&gt;</span></td>
      </tr>
      <tr>
        <td id="L198" class="blob-num js-line-number" data-line-number="198"></td>
        <td id="LC198" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L199" class="blob-num js-line-number" data-line-number="199"></td>
        <td id="LC199" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L200" class="blob-num js-line-number" data-line-number="200"></td>
        <td id="LC200" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;summary&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L201" class="blob-num js-line-number" data-line-number="201"></td>
        <td id="LC201" class="blob-code js-file-line">	<span class="nt">&lt;p&gt;</span><span class="k">&lt;xsl:apply-templates</span><span class="nt">/&gt;&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L202" class="blob-num js-line-number" data-line-number="202"></td>
        <td id="LC202" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L203" class="blob-num js-line-number" data-line-number="203"></td>
        <td id="LC203" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L204" class="blob-num js-line-number" data-line-number="204"></td>
        <td id="LC204" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;param&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L205" class="blob-num js-line-number" data-line-number="205"></td>
        <td id="LC205" class="blob-code js-file-line">	<span class="nt">&lt;tr&gt;</span></td>
      </tr>
      <tr>
        <td id="L206" class="blob-num js-line-number" data-line-number="206"></td>
        <td id="LC206" class="blob-code js-file-line">		<span class="nt">&lt;td</span> <span class="na">class=</span><span class="s">&quot;param&quot;</span><span class="nt">&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@name&quot;</span><span class="nt">/&gt;&lt;/td&gt;</span></td>
      </tr>
      <tr>
        <td id="L207" class="blob-num js-line-number" data-line-number="207"></td>
        <td id="LC207" class="blob-code js-file-line">		<span class="nt">&lt;td&gt;</span><span class="k">&lt;xsl:apply-templates</span><span class="nt">/&gt;&lt;/td&gt;</span></td>
      </tr>
      <tr>
        <td id="L208" class="blob-num js-line-number" data-line-number="208"></td>
        <td id="LC208" class="blob-code js-file-line">	<span class="nt">&lt;/tr&gt;</span></td>
      </tr>
      <tr>
        <td id="L209" class="blob-num js-line-number" data-line-number="209"></td>
        <td id="LC209" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L210" class="blob-num js-line-number" data-line-number="210"></td>
        <td id="LC210" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L211" class="blob-num js-line-number" data-line-number="211"></td>
        <td id="LC211" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;paraminfo&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L212" class="blob-num js-line-number" data-line-number="212"></td>
        <td id="LC212" class="blob-code js-file-line">	<span class="nt">&lt;span</span> <span class="na">class=</span><span class="s">&quot;paraminfo&quot;</span><span class="nt">&gt;</span><span class="ni">&amp;lt;</span><span class="k">&lt;xsl:apply-templates</span><span class="nt">/&gt;</span><span class="ni">&amp;gt;</span><span class="nt">&lt;/span&gt;</span></td>
      </tr>
      <tr>
        <td id="L213" class="blob-num js-line-number" data-line-number="213"></td>
        <td id="LC213" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L214" class="blob-num js-line-number" data-line-number="214"></td>
        <td id="LC214" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L215" class="blob-num js-line-number" data-line-number="215"></td>
        <td id="LC215" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;tagname&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L216" class="blob-num js-line-number" data-line-number="216"></td>
        <td id="LC216" class="blob-code js-file-line">	<span class="nt">&lt;p</span> <span class="na">class=</span><span class="s">&quot;noindent&quot;</span><span class="nt">&gt;&lt;table&gt;&lt;tr&gt;</span></td>
      </tr>
      <tr>
        <td id="L217" class="blob-num js-line-number" data-line-number="217"></td>
        <td id="LC217" class="blob-code js-file-line">		<span class="nt">&lt;td</span> <span class="na">class=</span><span class="s">&quot;header inline&quot;</span><span class="nt">&gt;</span>Tag<span class="nt">&lt;/td&gt;</span></td>
      </tr>
      <tr>
        <td id="L218" class="blob-num js-line-number" data-line-number="218"></td>
        <td id="LC218" class="blob-code js-file-line">		<span class="nt">&lt;td</span> <span class="na">class=</span><span class="s">&quot;inline&quot;</span><span class="nt">&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@value&quot;</span><span class="nt">/&gt;&lt;/td&gt;</span></td>
      </tr>
      <tr>
        <td id="L219" class="blob-num js-line-number" data-line-number="219"></td>
        <td id="LC219" class="blob-code js-file-line">	<span class="nt">&lt;/tr&gt;&lt;/table&gt;&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L220" class="blob-num js-line-number" data-line-number="220"></td>
        <td id="LC220" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L221" class="blob-num js-line-number" data-line-number="221"></td>
        <td id="LC221" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L222" class="blob-num js-line-number" data-line-number="222"></td>
        <td id="LC222" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;size&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L223" class="blob-num js-line-number" data-line-number="223"></td>
        <td id="LC223" class="blob-code js-file-line">	<span class="nt">&lt;p</span> <span class="na">class=</span><span class="s">&quot;noindent&quot;</span><span class="nt">&gt;&lt;table&gt;&lt;tr&gt;</span></td>
      </tr>
      <tr>
        <td id="L224" class="blob-num js-line-number" data-line-number="224"></td>
        <td id="LC224" class="blob-code js-file-line">		<span class="nt">&lt;td</span> <span class="na">class=</span><span class="s">&quot;header inline&quot;</span><span class="nt">&gt;</span>Size<span class="nt">&lt;/td&gt;</span></td>
      </tr>
      <tr>
        <td id="L225" class="blob-num js-line-number" data-line-number="225"></td>
        <td id="LC225" class="blob-code js-file-line">		<span class="nt">&lt;td</span> <span class="na">class=</span><span class="s">&quot;inline&quot;</span><span class="nt">&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@value&quot;</span><span class="nt">/&gt;&lt;/td&gt;</span></td>
      </tr>
      <tr>
        <td id="L226" class="blob-num js-line-number" data-line-number="226"></td>
        <td id="LC226" class="blob-code js-file-line">	<span class="nt">&lt;/tr&gt;&lt;/table&gt;&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L227" class="blob-num js-line-number" data-line-number="227"></td>
        <td id="LC227" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L228" class="blob-num js-line-number" data-line-number="228"></td>
        <td id="LC228" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L229" class="blob-num js-line-number" data-line-number="229"></td>
        <td id="LC229" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;returns&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L230" class="blob-num js-line-number" data-line-number="230"></td>
        <td id="LC230" class="blob-code js-file-line">	<span class="nt">&lt;h3&gt;</span>Returns<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L231" class="blob-num js-line-number" data-line-number="231"></td>
        <td id="LC231" class="blob-code js-file-line">	<span class="nt">&lt;p&gt;</span><span class="k">&lt;xsl:apply-templates</span><span class="nt">/&gt;&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L232" class="blob-num js-line-number" data-line-number="232"></td>
        <td id="LC232" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L233" class="blob-num js-line-number" data-line-number="233"></td>
        <td id="LC233" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L234" class="blob-num js-line-number" data-line-number="234"></td>
        <td id="LC234" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;location&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L235" class="blob-num js-line-number" data-line-number="235"></td>
        <td id="LC235" class="blob-code js-file-line">	<span class="nt">&lt;h3&gt;</span>Defined in<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L236" class="blob-num js-line-number" data-line-number="236"></td>
        <td id="LC236" class="blob-code js-file-line">	<span class="nt">&lt;p&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@file&quot;</span><span class="nt">/&gt;</span>, line <span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@line&quot;</span><span class="nt">/&gt;&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L237" class="blob-num js-line-number" data-line-number="237"></td>
        <td id="LC237" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L238" class="blob-num js-line-number" data-line-number="238"></td>
        <td id="LC238" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L239" class="blob-num js-line-number" data-line-number="239"></td>
        <td id="LC239" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;remarks&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L240" class="blob-num js-line-number" data-line-number="240"></td>
        <td id="LC240" class="blob-code js-file-line">	<span class="nt">&lt;p&gt;</span><span class="k">&lt;xsl:apply-templates</span><span class="nt">/&gt;&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L241" class="blob-num js-line-number" data-line-number="241"></td>
        <td id="LC241" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L242" class="blob-num js-line-number" data-line-number="242"></td>
        <td id="LC242" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L243" class="blob-num js-line-number" data-line-number="243"></td>
        <td id="LC243" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;example&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L244" class="blob-num js-line-number" data-line-number="244"></td>
        <td id="LC244" class="blob-code js-file-line">	<span class="nt">&lt;h3&gt;</span>Example<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L245" class="blob-num js-line-number" data-line-number="245"></td>
        <td id="LC245" class="blob-code js-file-line">	<span class="nt">&lt;p&gt;</span><span class="k">&lt;xsl:apply-templates</span><span class="nt">/&gt;&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L246" class="blob-num js-line-number" data-line-number="246"></td>
        <td id="LC246" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L247" class="blob-num js-line-number" data-line-number="247"></td>
        <td id="LC247" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L248" class="blob-num js-line-number" data-line-number="248"></td>
        <td id="LC248" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;attribute&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L249" class="blob-num js-line-number" data-line-number="249"></td>
        <td id="LC249" class="blob-code js-file-line">	<span class="nt">&lt;li</span> <span class="na">class=</span><span class="s">&quot;attribute&quot;</span><span class="nt">&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@name&quot;</span><span class="nt">/&gt;&lt;/li&gt;</span></td>
      </tr>
      <tr>
        <td id="L250" class="blob-num js-line-number" data-line-number="250"></td>
        <td id="LC250" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L251" class="blob-num js-line-number" data-line-number="251"></td>
        <td id="LC251" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L252" class="blob-num js-line-number" data-line-number="252"></td>
        <td id="LC252" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;referrer&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L253" class="blob-num js-line-number" data-line-number="253"></td>
        <td id="LC253" class="blob-code js-file-line">	<span class="nt">&lt;li</span> <span class="na">class=</span><span class="s">&quot;referrer&quot;</span><span class="nt">&gt;&lt;a&gt;</span><span class="k">&lt;xsl:attribute</span> <span class="na">name=</span><span class="s">&quot;href&quot;</span><span class="nt">&gt;</span>#<span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@name&quot;</span><span class="nt">/&gt;</span><span class="k">&lt;/xsl:attribute&gt;&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@name&quot;</span><span class="nt">/&gt;</span>()<span class="nt">&lt;/a&gt;&lt;/li&gt;</span></td>
      </tr>
      <tr>
        <td id="L254" class="blob-num js-line-number" data-line-number="254"></td>
        <td id="LC254" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L255" class="blob-num js-line-number" data-line-number="255"></td>
        <td id="LC255" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L256" class="blob-num js-line-number" data-line-number="256"></td>
        <td id="LC256" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;dependency&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L257" class="blob-num js-line-number" data-line-number="257"></td>
        <td id="LC257" class="blob-code js-file-line">	<span class="nt">&lt;li</span> <span class="na">class=</span><span class="s">&quot;dependency&quot;</span><span class="nt">&gt;&lt;a&gt;</span><span class="k">&lt;xsl:attribute</span> <span class="na">name=</span><span class="s">&quot;href&quot;</span><span class="nt">&gt;</span>#<span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@name&quot;</span><span class="nt">/&gt;</span><span class="k">&lt;/xsl:attribute&gt;&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@name&quot;</span><span class="nt">/&gt;</span>()<span class="nt">&lt;/a&gt;&lt;/li&gt;</span></td>
      </tr>
      <tr>
        <td id="L258" class="blob-num js-line-number" data-line-number="258"></td>
        <td id="LC258" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L259" class="blob-num js-line-number" data-line-number="259"></td>
        <td id="LC259" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L260" class="blob-num js-line-number" data-line-number="260"></td>
        <td id="LC260" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;stacksize&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L261" class="blob-num js-line-number" data-line-number="261"></td>
        <td id="LC261" class="blob-code js-file-line">	<span class="nt">&lt;h3&gt;</span>Estimated stack usage<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L262" class="blob-num js-line-number" data-line-number="262"></td>
        <td id="LC262" class="blob-code js-file-line">	<span class="nt">&lt;p&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@value&quot;</span><span class="nt">/&gt;</span> cells<span class="nt">&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L263" class="blob-num js-line-number" data-line-number="263"></td>
        <td id="LC263" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L264" class="blob-num js-line-number" data-line-number="264"></td>
        <td id="LC264" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L265" class="blob-num js-line-number" data-line-number="265"></td>
        <td id="LC265" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;automaton&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L266" class="blob-num js-line-number" data-line-number="266"></td>
        <td id="LC266" class="blob-code js-file-line">	<span class="nt">&lt;h3&gt;</span>Automaton<span class="nt">&lt;/h3&gt;</span></td>
      </tr>
      <tr>
        <td id="L267" class="blob-num js-line-number" data-line-number="267"></td>
        <td id="LC267" class="blob-code js-file-line">	<span class="nt">&lt;p&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@name&quot;</span><span class="nt">/&gt;&lt;/p&gt;</span></td>
      </tr>
      <tr>
        <td id="L268" class="blob-num js-line-number" data-line-number="268"></td>
        <td id="LC268" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L269" class="blob-num js-line-number" data-line-number="269"></td>
        <td id="LC269" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L270" class="blob-num js-line-number" data-line-number="270"></td>
        <td id="LC270" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;transition&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L271" class="blob-num js-line-number" data-line-number="271"></td>
        <td id="LC271" class="blob-code js-file-line">	<span class="nt">&lt;tr&gt;</span></td>
      </tr>
      <tr>
        <td id="L272" class="blob-num js-line-number" data-line-number="272"></td>
        <td id="LC272" class="blob-code js-file-line">		<span class="nt">&lt;td</span> <span class="na">class=</span><span class="s">&quot;transition&quot;</span><span class="nt">&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@source&quot;</span><span class="nt">/&gt;&lt;/td&gt;</span></td>
      </tr>
      <tr>
        <td id="L273" class="blob-num js-line-number" data-line-number="273"></td>
        <td id="LC273" class="blob-code js-file-line">		<span class="nt">&lt;td</span> <span class="na">class=</span><span class="s">&quot;transition&quot;</span><span class="nt">&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@target&quot;</span><span class="nt">/&gt;&lt;/td&gt;</span></td>
      </tr>
      <tr>
        <td id="L274" class="blob-num js-line-number" data-line-number="274"></td>
        <td id="LC274" class="blob-code js-file-line">		<span class="nt">&lt;td&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@condition&quot;</span><span class="nt">/&gt;&lt;/td&gt;</span></td>
      </tr>
      <tr>
        <td id="L275" class="blob-num js-line-number" data-line-number="275"></td>
        <td id="LC275" class="blob-code js-file-line">	<span class="nt">&lt;/tr&gt;</span></td>
      </tr>
      <tr>
        <td id="L276" class="blob-num js-line-number" data-line-number="276"></td>
        <td id="LC276" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L277" class="blob-num js-line-number" data-line-number="277"></td>
        <td id="LC277" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L278" class="blob-num js-line-number" data-line-number="278"></td>
        <td id="LC278" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;code&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L279" class="blob-num js-line-number" data-line-number="279"></td>
        <td id="LC279" class="blob-code js-file-line">	<span class="nt">&lt;pre&gt;</span><span class="k">&lt;xsl:apply-templates</span><span class="nt">/&gt;&lt;/pre&gt;</span></td>
      </tr>
      <tr>
        <td id="L280" class="blob-num js-line-number" data-line-number="280"></td>
        <td id="LC280" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L281" class="blob-num js-line-number" data-line-number="281"></td>
        <td id="LC281" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L282" class="blob-num js-line-number" data-line-number="282"></td>
        <td id="LC282" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;seealso&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L283" class="blob-num js-line-number" data-line-number="283"></td>
        <td id="LC283" class="blob-code js-file-line">	<span class="nt">&lt;li</span> <span class="na">class=</span><span class="s">&quot;seealso&quot;</span><span class="nt">&gt;&lt;a&gt;</span><span class="k">&lt;xsl:attribute</span> <span class="na">name=</span><span class="s">&quot;href&quot;</span><span class="nt">&gt;</span>#<span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@name&quot;</span><span class="nt">/&gt;</span><span class="k">&lt;/xsl:attribute&gt;&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@name&quot;</span><span class="nt">/&gt;</span>()<span class="nt">&lt;/a&gt;&lt;/li&gt;</span></td>
      </tr>
      <tr>
        <td id="L284" class="blob-num js-line-number" data-line-number="284"></td>
        <td id="LC284" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L285" class="blob-num js-line-number" data-line-number="285"></td>
        <td id="LC285" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L286" class="blob-num js-line-number" data-line-number="286"></td>
        <td id="LC286" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;paramref&quot;</span><span class="nt">&gt;</span></td>
      </tr>
      <tr>
        <td id="L287" class="blob-num js-line-number" data-line-number="287"></td>
        <td id="LC287" class="blob-code js-file-line">	<span class="nt">&lt;i&gt;</span><span class="k">&lt;xsl:value-of</span> <span class="na">select=</span><span class="s">&quot;@name&quot;</span><span class="nt">/&gt;&lt;/i&gt;</span></td>
      </tr>
      <tr>
        <td id="L288" class="blob-num js-line-number" data-line-number="288"></td>
        <td id="LC288" class="blob-code js-file-line"><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L289" class="blob-num js-line-number" data-line-number="289"></td>
        <td id="LC289" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L290" class="blob-num js-line-number" data-line-number="290"></td>
        <td id="LC290" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;c&quot;</span><span class="nt">&gt;&lt;code&gt;</span><span class="k">&lt;xsl:apply-templates</span><span class="nt">/&gt;&lt;/code&gt;</span><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L291" class="blob-num js-line-number" data-line-number="291"></td>
        <td id="LC291" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L292" class="blob-num js-line-number" data-line-number="292"></td>
        <td id="LC292" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;em&quot;</span><span class="nt">&gt;&lt;em&gt;</span><span class="k">&lt;xsl:apply-templates</span><span class="nt">/&gt;&lt;/em&gt;</span><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L293" class="blob-num js-line-number" data-line-number="293"></td>
        <td id="LC293" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L294" class="blob-num js-line-number" data-line-number="294"></td>
        <td id="LC294" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;ul&quot;</span><span class="nt">&gt;&lt;ul&gt;</span><span class="k">&lt;xsl:apply-templates</span><span class="nt">/&gt;&lt;/ul&gt;</span><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L295" class="blob-num js-line-number" data-line-number="295"></td>
        <td id="LC295" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L296" class="blob-num js-line-number" data-line-number="296"></td>
        <td id="LC296" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;ol&quot;</span><span class="nt">&gt;&lt;ol&gt;</span><span class="k">&lt;xsl:apply-templates</span><span class="nt">/&gt;&lt;/ol&gt;</span><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L297" class="blob-num js-line-number" data-line-number="297"></td>
        <td id="LC297" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L298" class="blob-num js-line-number" data-line-number="298"></td>
        <td id="LC298" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;li&quot;</span><span class="nt">&gt;&lt;li&gt;</span><span class="k">&lt;xsl:apply-templates</span><span class="nt">/&gt;&lt;/li&gt;</span><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L299" class="blob-num js-line-number" data-line-number="299"></td>
        <td id="LC299" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L300" class="blob-num js-line-number" data-line-number="300"></td>
        <td id="LC300" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;p&quot;</span><span class="nt">&gt;&lt;br/&gt;</span><span class="k">&lt;xsl:apply-templates</span><span class="nt">/&gt;</span><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L301" class="blob-num js-line-number" data-line-number="301"></td>
        <td id="LC301" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L302" class="blob-num js-line-number" data-line-number="302"></td>
        <td id="LC302" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;para&quot;</span><span class="nt">&gt;&lt;br/&gt;</span><span class="k">&lt;xsl:apply-templates</span><span class="nt">/&gt;</span><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L303" class="blob-num js-line-number" data-line-number="303"></td>
        <td id="LC303" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L304" class="blob-num js-line-number" data-line-number="304"></td>
        <td id="LC304" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;section&quot;</span><span class="nt">&gt;&lt;h2</span> <span class="na">class=</span><span class="s">&quot;general&quot;</span><span class="nt">&gt;</span><span class="k">&lt;xsl:apply-templates</span><span class="nt">/&gt;&lt;/h2&gt;</span><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L305" class="blob-num js-line-number" data-line-number="305"></td>
        <td id="LC305" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L306" class="blob-num js-line-number" data-line-number="306"></td>
        <td id="LC306" class="blob-code js-file-line"><span class="k">&lt;xsl:template</span> <span class="na">match=</span><span class="s">&quot;subsection&quot;</span><span class="nt">&gt;&lt;h3</span> <span class="na">class=</span><span class="s">&quot;general&quot;</span><span class="nt">&gt;</span><span class="k">&lt;xsl:apply-templates</span><span class="nt">/&gt;&lt;/h3&gt;</span><span class="k">&lt;/xsl:template&gt;</span></td>
      </tr>
      <tr>
        <td id="L307" class="blob-num js-line-number" data-line-number="307"></td>
        <td id="LC307" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L308" class="blob-num js-line-number" data-line-number="308"></td>
        <td id="LC308" class="blob-code js-file-line"><span class="k">&lt;/xsl:stylesheet&gt;</span></td>
      </tr>
</table>

  </div>

  </div>
</div>

<a href="#jump-to-line" rel="facebox[.linejump]" data-hotkey="l" style="display:none">Jump to Line</a>
<div id="jump-to-line" style="display:none">
  <form accept-charset="UTF-8" class="js-jump-to-line-form">
    <input class="linejump-input js-jump-to-line-field" type="text" placeholder="Jump to line&hellip;" autofocus>
    <button type="submit" class="button">Go</button>
  </form>
</div>

        </div>

      </div><!-- /.repo-container -->
      <div class="modal-backdrop"></div>
    </div><!-- /.container -->
  </div><!-- /.site -->


    </div><!-- /.wrapper -->

      <div class="container">
  <div class="site-footer">
    <ul class="site-footer-links right">
      <li><a href="https://status.github.com/">Status</a></li>
      <li><a href="http://developer.github.com">API</a></li>
      <li><a href="http://training.github.com">Training</a></li>
      <li><a href="http://shop.github.com">Shop</a></li>
      <li><a href="/blog">Blog</a></li>
      <li><a href="/about">About</a></li>

    </ul>

    <a href="/" aria-label="Homepage">
      <span class="mega-octicon octicon-mark-github" title="GitHub"></span>
    </a>

    <ul class="site-footer-links">
      <li>&copy; 2014 <span title="0.05166s from github-fe130-cp1-prd.iad.github.net">GitHub</span>, Inc.</li>
        <li><a href="/site/terms">Terms</a></li>
        <li><a href="/site/privacy">Privacy</a></li>
        <li><a href="/security">Security</a></li>
        <li><a href="/contact">Contact</a></li>
    </ul>
  </div><!-- /.site-footer -->
</div><!-- /.container -->


    <div class="fullscreen-overlay js-fullscreen-overlay" id="fullscreen_overlay">
  <div class="fullscreen-container js-suggester-container">
    <div class="textarea-wrap">
      <textarea name="fullscreen-contents" id="fullscreen-contents" class="fullscreen-contents js-fullscreen-contents js-suggester-field" placeholder=""></textarea>
    </div>
  </div>
  <div class="fullscreen-sidebar">
    <a href="#" class="exit-fullscreen js-exit-fullscreen tooltipped tooltipped-w" aria-label="Exit Zen Mode">
      <span class="mega-octicon octicon-screen-normal"></span>
    </a>
    <a href="#" class="theme-switcher js-theme-switcher tooltipped tooltipped-w"
      aria-label="Switch themes">
      <span class="octicon octicon-color-mode"></span>
    </a>
  </div>
</div>



    <div id="ajax-error-message" class="flash flash-error">
      <span class="octicon octicon-alert"></span>
      <a href="#" class="octicon octicon-x flash-close js-ajax-error-dismiss" aria-label="Dismiss error"></a>
      Something went wrong with that request. Please try again.
    </div>


      <script crossorigin="anonymous" src="https://assets-cdn.github.com/assets/frameworks-0c1b00f7935ae85624f5fc5d40d52d60febf92b4.js" type="text/javascript"></script>
      <script async="async" crossorigin="anonymous" src="https://assets-cdn.github.com/assets/github-5ecb6588735013bbe8940399e4154ceea28b35f9.js" type="text/javascript"></script>
      
      
        <script async src="https://www.google-analytics.com/analytics.js"></script>
  </body>
</html>

