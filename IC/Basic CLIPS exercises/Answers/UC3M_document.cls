\NeedsTeXFormat{LaTeX2e}                                                    % Tells the compiler which version of LaTeX the package is for.
\ProvidesClass{UC3M_document}[Template for UC3M work report]                % Gives the compiler some information about your package.
\LoadClass{article}                                                         % Our template is based on article.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%               UC3M Work report template              %
%           Universidad Carlos III de Madrid           %
%              Author: Aitor Alonso Núñez              %
%              Last update: January 2019               %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%% Required Packages %%%%%
\RequirePackage[pdftex, usenames, dvipsnames]{color}                            % So that we can define colors and change color fonts.
\RequirePackage[table,xcdraw]{xcolor}                                           % So that we can color tables cells, row, columns...
\definecolor{gray97}{gray}{.97}
\definecolor{gray75}{gray}{.75}
\definecolor{gray45}{gray}{.45}
\RequirePackage{ragged2e}                                                       % To allign some lines.
\RequirePackage{txfonts} 
\RequirePackage[T1]{fontenc}                                                    % Because we use vectorial fonts (type-1).
\RequirePackage[utf8]{inputenc}
\RequirePackage{courier}                                                        % To add code snippets.
\RequirePackage{geometry}                                                       % To define paper format and general margins.
\RequirePackage{graphicx}                                                       % To add images and graphics.
\RequirePackage[spanish, es-noindentfirst, es-noshorthands, es-tabla]{babel}    % Language format package (Spanish).
\RequirePackage{setspace}                                                       % Used when we modify spacing between lines.
\RequirePackage{fancyhdr}                                                       % So that we can add header and footer.
\RequirePackage{titlesec}                                                       % Useful to set title styles.
\RequirePackage{afterpage}                                                      % To change backgroud colors per page.
\RequirePackage{float}                                                          % Important on figures.
\RequirePackage[utf8]{inputenc}                                                 % UTF-8 input encode always!!
\RequirePackage{multirow}                                                       % So that we can merge cells in tables
\RequirePackage{xkeyval}                                                        % Macros
\RequirePackage{textcomp}                                                       % To write symbols like €
\RequirePackage{caption}                                                        % To add captions
\RequirePackage{subcaption}                                                     % To add subcaptions
\RequirePackage[
    hidelinks,                                                                  % Remove borders from links and refrences
    colorlinks=true,                                                            % Links and references have colors
    allcolors=uc3mNewBlue,                                                      % Set links and references color
    linktoc=all]                                                                % Title and page number of table of contents as symlink
    {hyperref}                                                                  % Index elements works as cross references. Also functional links to internet pages
\RequirePackage{nameref}                                                        % Allow to add labels with \label{name} which can be reference with \nameref{name}
\RequirePackage{array}                                                          % Table formating

% LISTADOS DE CÓDIGO
% soporte y estilo para listados de código. Más información en https://es.wikibooks.org/wiki/Manual_de_LaTeX/Listados_de_código/Listados_con_listings
\usepackage{listings}

% definimos un estilo de listings
\lstdefinestyle{estilo}{ frame=Ltb,
  framerule=0pt,
  aboveskip=0.5cm,
  framextopmargin=3pt,
  framexbottommargin=3pt,
  framexleftmargin=0.4cm,
  framesep=0pt,
  rulesep=.4pt,
  backgroundcolor=\color{gray97},
  rulesepcolor=\color{black},
  %
  basicstyle=\ttfamily\footnotesize,
  keywordstyle=\bfseries,
  stringstyle=\ttfamily,
  showstringspaces = false,
  commentstyle=\color{gray45},     
  %
  numbers=left,
  numbersep=15pt,
  numberstyle=\tiny,
  numberfirstline = false,
  breaklines=true,
  xleftmargin=\parindent
}

\captionsetup[lstlisting]{font=small, labelsep=period}
% fijamos el estilo a utilizar 
\lstset{style=estilo}
\renewcommand{\lstlistingname}{\uppercase{Código}}

%%%%% Colors %%%%%
\definecolor{gray}{rgb}{0.2509803922, 0.2509803922, 0.2509803922}
\definecolor{grayLight}{rgb}{0.4980392157, 0.4980392157, 0.4980392157}
% Color UC3M corporative identity
% - Old corporative identity
\definecolor{uc3mDarkBlue}{RGB}{0, 7, 121}
\definecolor{uc3mBlue}{RGB}{32, 85, 138}
\definecolor{uc3mLightBlue}{RGB}{99, 158, 200}
% - New corporative identity
\definecolor{uc3mNewBlue}{RGB}{0, 29, 133}

%%%%% Margins %%%%%
\setlength{\headheight}{60pt}   % Header height (vertical size)
\setlength{\footskip}{20pt}     % Footer height (vertical size)
\geometry{
    a4paper,        % Use A4 paper
    tmargin=39mm,   % Distance (margin) from document content (including header) to sheet top border
    bmargin=29mm,   % Distance (margin) from document content (including footer) to sheet bottom border
    lmargin=25mm,   % Distance (margin) from document content to sheet left border
    rmargin=20mm    % Distance (margin) from document content to sheet right border
}

\onehalfspace                      % Spacing between lines.
\setlength{\parindent}{0cm}        % Indent length.

% \def\changemargin#1#2{\list{}{\rightmargin#2\leftmargin#1}\item[]}
% \let\endchangemargin=\endlist      %To change margins of a few lines.

%%%%% Lists formating %%%%%
\renewcommand{\labelitemi}{\textcolor{uc3mNewBlue}{$\bullet$}}
\renewcommand{\labelitemii}{\textcolor{uc3mNewBlue}{$\circ$}}
\renewcommand{\labelitemiii}{\textcolor{uc3mNewBlue}{\textbullet}}
\renewcommand{\labelitemiv}{\textcolor{uc3mNewBlue}{$\diamond$}}
\renewcommand{\@listI}{ % List margins
    \leftmargin=25pt
    \rightmargin=0pt
    \labelsep=5pt
    \labelwidth=20pt
    \itemindent=0pt
    \listparindent=0pt
    \topsep=-5pt
    \partopsep=0pt plus 1pt minus 1pt
    \parsep=0pt plus 1pt
    \itemsep=\parsep
}

%%%%% Table formating %%%%%
\renewcommand{\arraystretch}{1.25} % Table cells margin
\newcommand{\hcell}[1]{\cellcolor{uc3mNewBlue}{\color{white} \textbf{#1}}} % Table header cell, blue background with white bold text.
% Table cells with fixed size
\newcolumntype{L}[1]{>{\raggedright\let\newline\\\arraybackslash\hspace{0pt}}m{#1}} % Left aligned
\newcolumntype{C}[1]{>{\centering\let\newline\\\arraybackslash\hspace{0pt}}m{#1}} % Centered
\newcolumntype{R}[1]{>{\raggedleft\let\newline\\\arraybackslash\hspace{0pt}}m{#1}} % Right aligned

%%%%% Some booleans to format header and title page %%%%%
\newif\ifauthorstwo
\newif\ifauthorsthree
\newif\ifauthorsfour
\newif\ifemail

%%%%% Coauthors (students), NIA and group, up to three coauthors %%%%%
\newcommand{\authorsuptothree}[9]{
    \def\authorI{#1}
    \def\niaI{#2}
    \def\groupI{#3}
    \def\authorII{#4}
    \def\niaII{#5}
    \def\groupII{#6}
    \def\authorIII{#7}
    \def\niaIII{#8}
    \def\groupIII{#9}
}

%%%%% Coauthors (students) with NIA and without group, four coauthors %%%%%
\newcommand{\authorsfour}[9]{
    \def\authorIofIV{#1}
    \def\niaIofIV{#2}
    \def\authorIIofIV{#3}
    \def\niaIIofIV{#4}
    \def\authorIIIofIV{#5}
    \def\niaIIIofIV{#6}
    \def\authorIVofIV{#7}
    \def\niaIVofIV{#8}
    \def\groupIV{#9}
}

%%%%% Basic data about document (degree, subject, document title, campus and page number custom text) %%%%%
\newcommand{\documentdata}[5]{
    \def\studyname{#1}
    \def\subjectname{#2}
    \def\documenttitle{#3}
    \def\campus{#4}
    \def\mypagename{#5}
}

%%%%% Email addresses of document coauthors %%%%
\newcommand{\emails}[4]{
    \def\emailI{#1}
    \def\emailII{#2}
    \def\emailIII{#3}
    \def\emailIV{#4}
}

%%%%% Header %%%%%
\newcommand{\header}[0]{
    %%%% Left part of header %%%%
    \ifauthorstwo
    \lhead{
        \hspace*{-1em}
        \textcolor{gray}{
        \vspace*{-\baselineskip} % To remove white spaces up and down the header table
        \begin{tabular}{lll}
        \authorI & \niaI\\
        \authorII & \niaII
        \end{tabular}}
    }
    \fi
    \ifauthorsthree
    \lhead{
        \hspace*{-1em}
        \textcolor{gray}{
        \vspace*{-\baselineskip} % To remove white spaces up and down the header table
        \begin{tabular}{ll}
        \authorI & \niaI\\
        \authorII & \niaII\\
        \authorIII & \niaIII
        \end{tabular}}
    }
    \fi
    \ifauthorsfour
    \lhead{
        \hspace*{-1em}
        \textcolor{gray}{
        \vspace*{-\baselineskip} % To remove white spaces up and down the header table
        \begin{tabular}{ll}
        \authorIofIV & \niaIofIV\\
        \authorIIofIV & \niaIIofIV\\
        \authorIIIofIV & \niaIIIofIV\\
        \authorIVofIV & \niaIVofIV\\
        \end{tabular}}
    }
    \fi

    %%%% Right part of header %%%%
    \ifauthorsfour
        \rhead{\includegraphics[scale=0.12]{img/logo_completo_horizontal.png}} % Logo image uc3m
    \else
        \rhead{
        \vspace*{-\baselineskip} % To remove white spaces up and down the header table
        \begin{tabular}{c}
        \includegraphics[scale=0.12]{img/logo_completo_horizontal.png} % Logo image uc3m
        \end{tabular}}
    \fi
    \renewcommand{\headrulewidth}{0pt}  % To erase header line
}

%%%%% Footer %%%%%
\newcommand{\footer}[0]{
    \renewcommand{\footrulewidth}{0.1pt}  % Separation rule
    \cfoot{\vspace{1mm}\textcolor{uc3mNewBlue}{Universidad Carlos III de Madrid - \campus}
    \textcolor{uc3mNewBlue}{\\\studyname
    \\\subjectname}}
    \rfoot{\vspace{1mm} \mypagename \thepage} % Current page
}

%%%%% Paragraph style %%%%%
% \newcommand{\p}{\justify\mdseries\normalsize{\hspace{0cm}}} % \justify\mdseries\normalsize{\hspace{0cm}}}
\setlength{\parindent}{0em}
\setlength{\parskip}{1em}


%%%%% Section style %%%%%
\titleformat{\section}{
    \large\bfseries\color{uc3mNewBlue}{}\setlength{\parskip}{0em}}
    {}{0em}
      {}
      [\color{uc3mNewBlue}{\titlerule[2pt]}\vspace{-0.5em}]


%%%%% Subsection style %%%%%
\titleformat{\subsection}{
    \normalsize\bfseries\color{uc3mNewBlue}{}\setlength{\parskip}{0em}}
    {}{0em}
      {}
      [\vspace{-1em}]


%%%%% Subsubsection style %%%%%
\titleformat{\subsubsection}{
    \normalsize\color{uc3mNewBlue}{}\setlength{\parskip}{0em}}
    {}{0em}
      {}
      [\vspace{-1em}]


%Título e imagen centrado
%1 -> Nombre de la imagen
%2 -> Carrera
%3 -> Curso
%4 -> Asignatura
%5 -> Título práctica
\newcommand{\centeredtitle}[5]{
  \begin{center}
    \vspace{10mm}

    \includegraphics[width=80mm]{#1}

    \LARGE #2

    \vspace{5mm}

    \Large #3

    \vspace{25mm}

    \textbf{\LARGE #4}

    \vspace{10mm}

    \textbf{\Huge #5}

    \vspace{40mm}
  \end{center}
  \normalsize
}