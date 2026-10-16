
<!DOCTYPE html>
<html lang="de">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Informationen für Eltern | Accenture</title>

  <style>
    :root {
      --purple: #A100FF;
      --white: #FFFFFF;
      --black: #000000;
    }

    * {
      box-sizing: border-box;
      margin: 0;
      padding: 0;
    }

    html { scroll-behavior: smooth; }

    body {
      min-height: 100vh;
      background: var(--black);
      color: var(--white);
      font-family: Arial, Helvetica, sans-serif;
      overflow-x: hidden;
    }

    /* KOPFBEREICH */

    header {
      position: absolute;
      top: 0;
      left: 0;
      z-index: 10;
      width: 100%;
      padding: 30px 5%;
      display: flex;
      align-items: center;
      justify-content: space-between;
      gap: 24px;
      animation: headerAppear 0.8s ease both;
    }

    .logo {
      display: inline-flex;
      align-items: center;
      gap: 12px;
      text-decoration: none;
      color: var(--white);
      flex-shrink: 0;
    }

    .logo-symbol {
      color: var(--purple);
      font-size: 64px;
      line-height: 0.8;
      font-weight: 900;
      letter-spacing: -10px;
      padding-right: 8px;
      transition: transform 0.35s ease;
    }

    .logo-name {
      font-size: 20px;
      font-weight: 700;
      opacity: 0;
      transform: translateY(8px);
      transition: opacity 0.3s ease, transform 0.3s ease;
    }

    .logo:hover .logo-symbol,
    .logo:focus-visible .logo-symbol {
      transform: translateY(-4px);
    }

    .logo:hover .logo-name,
    .logo:focus-visible .logo-name {
      opacity: 1;
      transform: translateY(0);
    }

    nav {
      display: flex;
      align-items: center;
      gap: 18px;
    }

    .nav-button {
      display: inline-flex;
      align-items: center;
      gap: 12px;
      padding: 12px 0 12px 17px;
      color: var(--white);
      background: transparent;
      border: none;
      text-decoration: none;
      font-size: 15px;
      font-weight: 700;
      cursor: pointer;
      transition: color 0.25s ease;
      white-space: nowrap;
    }

    .nav-button:hover,
    .nav-button:focus-visible {
      color: var(--purple);
    }

    .nav-arrow {
      font-size: 21px;
      transition: transform 0.25s ease;
    }

    .nav-button:hover .nav-arrow {
      transform: translateX(4px);
    }

    .language-select {
      max-width: 150px;
      padding: 10px 12px;
      color: #fff;
      background: #151515;
      border: 1px solid #444;
      border-radius: 4px;
      font: inherit;
      font-size: 14px;
      cursor: pointer;
      transition: border-color 0.25s ease;
    }

    .language-select:hover,
    .language-select:focus-visible {
      border-color: var(--purple);
      outline: none;
    }

    .language-select option {
      color: #111;
      background: #fff;
    }

    /* HERO-BEREICH */

    main {
      min-height: 100vh;
      padding: 150px 5% 70px;
      display: flex;
      flex-direction: column;
      align-items: center;
      justify-content: center;
      text-align: center;
    }

    .headline {
      display: flex;
      flex-direction: column;
      align-items: center;
      font-weight: 900;
      font-style: italic;
      line-height: 0.88;
      letter-spacing: -0.065em;
      animation: headlineAppear 1s cubic-bezier(.2, .8, .2, 1) both;
    }

    .headline span {
      display: block;
      transition:
        transform 0.65s cubic-bezier(.2, .8, .2, 1),
        color 0.35s ease;
    }

    .information {
      color: var(--purple);
      font-size: clamp(2.5rem, 9.5vw, 9rem);
    }

    .fuer {
      margin: 16px 0;
      color: var(--white);
      font-size: clamp(3rem, 8vw, 7rem);
    }

    .eltern {
      color: var(--purple);
      font-size: clamp(3.5rem, 11vw, 10rem);
    }

    .headline:hover .information {
      transform: translateX(-5vw);
    }

    .headline:hover .fuer {
      transform: scale(1.06);
    }

    .headline:hover .eltern {
      transform: translateX(5vw);
    }

    .slogan {
      max-width: 850px;
      margin-top: 42px;
      font-size: clamp(1rem, 2.1vw, 1.5rem);
      line-height: 1.6;
      font-weight: 400;
      color: var(--white);
      animation: sloganAppear 1s 0.35s ease both;
    }

    .purple-word { color: var(--purple); }

    .accent-line {
      width: 70px;
      height: 4px;
      margin-top: 32px;
      background: var(--purple);
      transform-origin: center;
      animation: lineAppear 0.8s 0.7s ease both;
    }

    /* ANIMATIONEN */

    @keyframes headerAppear {
      from { opacity: 0; transform: translateY(-15px); }
      to { opacity: 1; transform: translateY(0); }
    }

    @keyframes headlineAppear {
      from { opacity: 0; transform: translateY(35px); }
      to { opacity: 1; transform: translateY(0); }
    }

    @keyframes sloganAppear {
      from { opacity: 0; transform: translateY(18px); }
      to { opacity: 1; transform: translateY(0); }
    }

    @keyframes lineAppear {
      from { opacity: 0; transform: scaleX(0); }
      to { opacity: 1; transform: scaleX(1); }
    }

    /* INHALTSBEREICHE */

    .content-section {
      width: 100%;
      padding: 75px 8%;
      background: #0b0b0b;
      border-top: 1px solid #252525;
      text-align: left;
    }

    .section-heading {
      display: flex;
      align-items: center;
      gap: 16px;
      margin-bottom: 38px;
    }

    .section-number {
      color: var(--purple);
      font-size: 15px;
      font-weight: 800;
      letter-spacing: 1px;
      white-space: nowrap;
    }

    .section-heading h2 {
      color: var(--white);
      font-size: clamp(1.5rem, 3vw, 2.3rem);
      font-weight: 800;
      letter-spacing: -0.04em;
      line-height: 1.2;
    }

    .section-heading::after {
      content: "";
      flex: 1;
      height: 1px;
      background: #444;
      margin-left: 10px;
    }

    /* ÜBER UNS – ORIGINALTEXT */

    .about-section { background: #0b0b0b; }

    .about-text {
      max-width: 1050px;
      font-size: clamp(1.05rem, 1.8vw, 1.3rem);
      line-height: 1.9;
      color: #e5e5e5;
    }

    .about-text strong {
      color: var(--purple);
      font-weight: 700;
    }

    /* EIN PRAKTIKUM ZUM MITMACHEN */

    .participation-section { background: #080808; }

    .participation-intro {
      max-width: 850px;
      margin-bottom: 35px;
      color: #d0d0d0;
      font-size: 18px;
      line-height: 1.8;
    }

    .participation-intro strong { color: var(--purple); }

    /* PIKTOGRAMM-KACHELN */

    .tile-grid {
      display: grid;
      grid-template-columns: repeat(3, minmax(0, 1fr));
      gap: 16px;
    }

    .info-tile {
      display: flex;
      align-items: center;
      gap: 17px;
      min-width: 0;
      min-height: 105px;
      padding: 20px;
      background: #141414;
      border: 1px solid #303030;
      border-radius: 5px;
      text-decoration: none;
      color: var(--white);
      transition:
        transform 0.3s ease,
        border-color 0.3s ease,
        background-color 0.3s ease;
    }

    .info-tile:hover,
    .info-tile:focus-visible {
      transform: translateY(-4px);
      border-color: var(--purple);
      background: #1b1022;
      outline: none;
    }

    .tile-icon {
      display: flex;
      flex-shrink: 0;
      align-items: center;
      justify-content: center;
      width: 48px;
      height: 48px;
      color: var(--purple);
      background: #251332;
      border-radius: 4px;
    }

    .tile-icon svg {
      width: 26px;
      height: 26px;
      fill: none;
      stroke: currentColor;
      stroke-width: 1.7;
      stroke-linecap: round;
      stroke-linejoin: round;
    }

    .tile-text { min-width: 0; }

    .tile-text h3 {
      margin-bottom: 6px;
      font-size: 17px;
      line-height: 1.35;
    }

    .tile-text p {
      color: #bdbdbd;
      font-size: 14px;
      line-height: 1.6;
    }

    /* TABELLE */

    .table-wrapper {
      width: 100%;
      overflow-x: auto;
      border: 1px solid #303030;
      border-radius: 5px;
      background: #141414;
    }

    .internship-table {
      width: 100%;
      border-collapse: collapse;
      text-align: left;
      line-height: 1.8;
    }

    .internship-table th {
      padding: 20px 24px;
      color: #fff;
      background: #251332;
      font-size: 16px;
      font-weight: 700;
    }

    .internship-table td {
      padding: 22px 24px;
      color: #d0d0d0;
      border-top: 1px solid #303030;
      vertical-align: top;
      font-size: 16px;
    }

    .internship-table td:first-child {
      width: 32%;
      color: var(--purple);
      font-weight: 700;
    }

    .internship-table tbody tr {
      transition: background-color 0.25s ease;
    }

    .internship-table tbody tr:hover {
      background: #1b1022;
    }

    /* PRAKTIKUMSZEITEN */

    .hours-section { background: #0b0b0b; }

    .hours-intro {
      margin-bottom: 24px;
      color: #c8c8c8;
      font-size: 17px;
      line-height: 1.7;
    }

    .hours-list {
      display: grid;
      grid-template-columns: repeat(2, minmax(0, 1fr));
      gap: 14px;
      list-style: none;
    }

    .hours-list li {
      display: flex;
      align-items: flex-start;
      gap: 13px;
      padding: 20px;
      background: #151515;
      border-left: 3px solid var(--purple);
      color: #eee;
      font-size: 16px;
      line-height: 1.7;
    }

    .hours-list li::before {
      content: "✓";
      color: var(--purple);
      font-weight: 900;
      font-size: 18px;
    }

    .hours-list strong { color: #fff; }

    /* WAS WIRD VERMITTELT? */

    .skills-section { background: #080808; }

    .skills-intro {
      max-width: 850px;
      margin-bottom: 30px;
      color: #c8c8c8;
      font-size: 17px;
      line-height: 1.8;
    }

    /* KONTAKT */

    .contact-section { background: #0b0b0b; }

    .contact-grid {
      display: grid;
      grid-template-columns: minmax(0, 1fr) minmax(0, 1.15fr);
      gap: 40px;
      align-items: start;
    }

    .contact-info h3 {
      margin-bottom: 25px;
      font-size: 23px;
    }

    .contact-item { margin-bottom: 25px; }

    .contact-item strong {
      display: block;
      margin-bottom: 8px;
      color: var(--purple);
      font-size: 14px;
      letter-spacing: 0.5px;
    }

    .contact-item p,
    .contact-item a {
      color: #dedede;
      font-size: 16px;
      line-height: 1.8;
      overflow-wrap: anywhere;
    }

    .contact-item a {
      text-decoration: none;
      transition: color 0.25s ease;
    }

    .contact-item a:hover,
    .contact-item a:focus-visible {
      color: var(--purple);
      text-decoration: underline;
    }

    .contact-note {
      margin-top: 25px;
      padding: 17px;
      border-left: 2px solid var(--purple);
      background: #141414;
      color: #bdbdbd;
      font-size: 14px;
      line-height: 1.8;
    }

    .map-container {
      overflow: hidden;
      border: 1px solid #383838;
      border-radius: 5px;
    }

    .map-container iframe {
      display: block;
      width: 100%;
      height: 350px;
      border: 0;
    }

    .map-caption {
      padding: 15px 18px;
      background: #151515;
      color: #bdbdbd;
      font-size: 13px;
      line-height: 1.7;
    }

    .map-caption strong { color: #fff; }

    /* FUSSZEILE */

    footer {
      display: flex;
      align-items: center;
      justify-content: space-between;
      gap: 20px;
      padding: 25px 8%;
      background: #000;
      border-top: 1px solid #292929;
      color: #888;
      font-size: 13px;
    }

    footer a {
      color: #c5c5c5;
      text-decoration: none;
    }

    footer a:hover { color: var(--purple); }

    /* SCROLL-ANIMATIONEN */

    .reveal {
      opacity: 0;
      transform: translateY(22px);
      transition: opacity 0.7s ease, transform 0.7s ease;
    }

    .reveal.visible {
      opacity: 1;
      transform: translateY(0);
    }

    /* RESPONSIVE */

    @media (max-width: 900px) {
      .content-section { padding: 60px 6%; }

      .tile-grid {
        grid-template-columns: repeat(2, minmax(0, 1fr));
      }

      .contact-grid { grid-template-columns: 1fr; }
    }

    @media (max-width: 600px) {
      header { padding: 22px 5%; }
      .logo-symbol { font-size: 48px; }
      .logo-name { display: none; }
      nav { gap: 8px; }

      .nav-button {
        padding: 10px 0 10px 5px;
        font-size: 13px;
        gap: 5px;
      }

      .language-select {
        max-width: 112px;
        padding: 9px 5px;
        font-size: 12px;
      }

      main { padding: 125px 4% 50px; }
      .headline { letter-spacing: -0.055em; }
      .information { font-size: clamp(2.1rem, 9vw, 3.8rem); }
      .fuer { margin: 12px 0; }
      .slogan { margin-top: 30px; }

      .headline:hover .information { transform: translateX(-2vw); }
      .headline:hover .eltern { transform: translateX(2vw); }

      .content-section { padding: 45px 6%; }

      .section-heading {
        gap: 10px;
        margin-bottom: 27px;
      }

      .section-heading h2 { font-size: 21px; }
      .section-heading::after { display: none; }

      .tile-grid,
      .hours-list {
        grid-template-columns: 1fr;
      }

      .info-tile { min-height: 88px; padding: 16px; }
      .tile-icon { width: 43px; height: 43px; }
      .map-container iframe { height: 290px; }

      .internship-table th,
      .internship-table td {
        padding: 15px 12px;
        font-size: 14px;
      }

      .internship-table td:first-child { width: 38%; }

      footer {
        align-items: flex-start;
        flex-direction: column;
        padding: 22px 6%;
      }
    }

    @media (prefers-reduced-motion: reduce) {
      *,
      *::before,
      *::after {
        animation-duration: 0.01ms !important;
        animation-iteration-count: 1 !important;
        scroll-behavior: auto !important;
        transition-duration: 0.01ms !important;
      }

      .reveal {
        opacity: 1;
        transform: none;
      }
    }
  </style>
</head>

<body>

  <!-- KOPFBEREICH -->

  <header>
    <a class="logo"
       href="https://www.accenture.com/de-de"
       target="_blank"
       rel="noopener noreferrer"
       aria-label="Accenture-Website öffnen">
      <span class="logo-symbol" aria-hidden="true">&gt;</span>
      <span class="logo-name">Accenture</span>
    </a>

    <nav aria-label="Hauptnavigation">
      <a class="nav-button" href="#startseite">
        <span data-i18n="navHome">Startseite</span>
        <span class="nav-arrow" aria-hidden="true">&gt;</span>
      </a>

      <select id="languageSelect" class="language-select"
              aria-label="Sprache auswählen">
        <option value="de">Deutsch</option>
        <option value="en">English</option>
        <option value="fr">Français</option>
        <option value="es">Español</option>
      </select>
    </nav>
  </header>

  <!-- STARTSEITE -->

  <main id="startseite">
    <h1 class="headline">
      <span class="information" data-i18n="heroInfo">INFORMATIONEN</span>
      <span class="fuer" data-i18n="heroFor">FÜR</span>
      <span class="eltern" data-i18n="heroParents">ELTERN</span>
    </h1>

    <p class="slogan">
      <span data-i18n="sloganFirst">Entdecke deine</span>
      <span class="purple-word" data-i18n="sloganPossibilities">Möglichkeiten.</span>
      <br>
      <span data-i18n="sloganSecond">Gestalte deine</span>
      <span class="purple-word" data-i18n="sloganFuture">Zukunft.</span>
    </p>

    <div class="accent-line" aria-hidden="true"></div>
  </main>

  <!-- 01 – ÜBER UNS -->

  <section class="content-section about-section reveal">
    <div class="section-heading">
      <span class="section-number">01</span>
      <h2 data-i18n="aboutTitle">Über uns</h2>
    </div>

    <p class="about-text">
      <em>
        <span data-i18n="aboutStart">Wir bei Accenture sind eine</span>
        <strong data-i18n="aboutConsulting">weltweit tätige Unternehmensberatung</strong>,
        <span data-i18n="aboutSupport">die Unternehmen in den Bereichen</span>
        <strong data-i18n="aboutFields">Strategie, Technologie, Digitalisierung und Innovation</strong>
        <span data-i18n="aboutSupportEnd">unterstützt. Mit rund</span>
        <strong data-i18n="aboutEmployees">780.000 Mitarbeitenden in über 120 Ländern</strong>
        <span data-i18n="aboutConnect">verbinden wir Fachwissen mit modernster Technologie, um</span>
        <strong data-i18n="aboutSustainable">nachhaltige Lösungen</strong>
        <span data-i18n="aboutFuture">zu entwickeln und die Zukunft aktiv mitzugestalten.</span>
      </em>
    </p>
  </section>

  <!-- 02 – EIN PRAKTIKUM ZUM MITMACHEN: KACHELN BLEIBEN -->

  <section class="content-section participation-section reveal">
    <div class="section-heading">
      <span class="section-number">02</span>
      <h2 data-i18n="participationTitle">Ein Praktikum zum Mitmachen</h2>
    </div>

    <p class="participation-intro" data-i18n="participationIntro">
      Das Praktikum verbindet neue Einblicke mit praktischer Erfahrung.
      Die Teilnehmenden arbeiten mit unterschiedlichen Betreuer:innen,
      bearbeiten Aufgaben allein und im Team und setzen ihre Ideen
      in eigenen Projekten um.
    </p>

    <div class="tile-grid">

      <a class="info-tile" href="#praktikumszeiten">
        <span class="tile-icon" aria-hidden="true">
          <svg viewBox="0 0 24 24">
            <rect x="3" y="4" width="18" height="16" rx="2"/>
            <path d="M8 2v4M16 2v4M3 9h18"/>
            <path d="m8 14 2 2 5-5"/>
          </svg>
        </span>
        <span class="tile-text">
          <h3 data-i18n="hoursTitle">Praktikumszeiten</h3>
          <p data-i18n="hoursTileDescription">Zeiten und Pausen im Überblick.</p>
        </span>
      </a>

      <a class="info-tile" href="#faehigkeiten">
        <span class="tile-icon" aria-hidden="true">
          <svg viewBox="0 0 24 24">
            <rect x="3" y="4" width="18" height="16" rx="2"/>
            <path d="m8 10-3 2 3 2M16 10l3 2-3 2M14 9l-4 6"/>
          </svg>
        </span>
        <span class="tile-text">
          <h3 data-i18n="digitalTileTitle">Digitale Fähigkeiten</h3>
          <p data-i18n="digitalTileDescription">Einblicke in Coding und Webanwendungen.</p>
        </span>
      </a>

      <a class="info-tile" href="#ablauf">
        <span class="tile-icon" aria-hidden="true">
          <svg viewBox="0 0 24 24">
            <circle cx="9" cy="8" r="3"/>
            <path d="M3 20v-2a6 6 0 0 1 12 0v2"/>
            <path d="M16 5a3 3 0 0 1 0 6M18 14a5 5 0 0 1 3 4v2"/>
          </svg>
        </span>
        <span class="tile-text">
          <h3 data-i18n="collaborationTitle">Zusammenarbeit</h3>
          <p data-i18n="collaborationDescription">Einzelaufgaben und Teamprojekte.</p>
        </span>
      </a>

    </div>
  </section>

  <!-- 03 – PRAKTIKUMSZEITEN -->

  <section class="content-section hours-section reveal" id="praktikumszeiten">
    <div class="section-heading">
      <span class="section-number">03</span>
      <h2 data-i18n="hoursTitle">Praktikumszeiten</h2>
    </div>

    <p class="hours-intro" data-i18n="hoursIntro">
      Die geplanten täglichen Zeiten im Überblick:
    </p>

    <ul class="hours-list">
      <li>
        <span>
          <strong data-i18n="mondayThursday">Montag bis Donnerstag</strong><br>
          09:00–16:00 Uhr
        </span>
      </li>
      <li>
        <span>
          <strong data-i18n="friday">Freitag</strong><br>
          09:00–15:00 Uhr
        </span>
      </li>
      <li>
        <span>
          <strong data-i18n="lunch">Mittagspause</strong><br>
          12:00–13:00 Uhr
        </span>
      </li>
      <li>
        <span>
          <strong data-i18n="breaks">Zusätzliche Pausen</strong><br>
          <span data-i18n="breaksDescription">Kurze Pausen während des Tages</span>
        </span>
      </li>
    </ul>
  </section>

  <!-- 04 – ABLAUF DES PRAKTIKUMS -->

  <section class="content-section participation-section reveal" id="ablauf">
    <div class="section-heading">
      <span class="section-number">04</span>
      <h2 data-i18n="workflowTitle">So wird das Praktikum gestaltet</h2>
    </div>

    <p class="participation-intro" data-i18n="workflowIntro">
      Je nach Thema begleiten unterschiedliche Betreuer:innen die
      Teilnehmenden. Neben Workshops gibt es praktische Aufgaben,
      Fallstudien und gemeinsame Projektarbeit.
    </p>

    <div class="tile-grid">

      <article class="info-tile">
        <span class="tile-icon" aria-hidden="true">
          <svg viewBox="0 0 24 24">
            <path d="M12 3 3 8l9 5 9-5-9-5Z"/>
            <path d="m3 12 9 5 9-5M3 16l9 5 9-5"/>
          </svg>
        </span>
        <div class="tile-text">
          <h3 data-i18n="workshopsTitle">Workshops</h3>
          <p data-i18n="workshopsDescription">Neue Themen kennenlernen und gemeinsam Lösungen erarbeiten.</p>
        </div>
      </article>

      <article class="info-tile">
        <span class="tile-icon" aria-hidden="true">
          <svg viewBox="0 0 24 24">
            <path d="M8 6h13M8 12h13M8 18h13"/>
            <path d="m3 6 1 1 2-2M3 12l1 1 2-2M3 18l1 1 2-2"/>
          </svg>
        </span>
        <div class="tile-text">
          <h3 data-i18n="casesTitle">Case Studies</h3>
          <p data-i18n="casesDescription">Praxisnahe Fragestellungen analysieren und Lösungsansätze entwickeln.</p>
        </div>
      </article>

      <article class="info-tile">
        <span class="tile-icon" aria-hidden="true">
          <svg viewBox="0 0 24 24">
            <rect x="3" y="4" width="18" height="16" rx="2"/>
            <path d="m8 10-3 2 3 2M16 10l3 2-3 2M14 9l-4 6"/>
          </svg>
        </span>
        <div class="tile-text">
          <h3 data-i18n="projectsTitle">Eigene Projekte</h3>
          <p data-i18n="projectsDescription">Ideen allein oder im Team in ein konkretes Ergebnis umsetzen.</p>
        </div>
      </article>

    </div>
  </section>

  <!-- 05 – WAS WIRD VERMITTELT?: TABELLE -->

  <section class="content-section skills-section reveal" id="faehigkeiten">
    <div class="section-heading">
      <span class="section-number">05</span>
      <h2 data-i18n="skillsTitle">Was wird vermittelt?</h2>
    </div>

    <p class="skills-intro" data-i18n="skillsIntro">
      Das Praktikum vermittelt grundlegende Kompetenzen für digitale
      Projekte – von der Zusammenarbeit bis zur Entwicklung einfacher
      Webanwendungen.
    </p>

    <div class="table-wrapper">
      <table class="internship-table">
        <thead>
          <tr>
            <th data-i18n="skillsTableTopic">Bereich</th>
            <th data-i18n="skillsTableContent">Was wird vermittelt?</th>
          </tr>
        </thead>
        <tbody>
          <tr>
            <td data-i18n="webTitle">Webanwendungen</td>
            <td data-i18n="webDescription">
              Grundlagen von HTML, CSS und JavaScript kennenlernen
              und für eigene digitale Anwendungen einsetzen.
            </td>
          </tr>
          <tr>
            <td data-i18n="digitalTitle">Digitale Lösungen</td>
            <td data-i18n="digitalDescription">
              Ideen entwickeln, Probleme analysieren und einfache
              technische Lösungen praktisch umsetzen.
            </td>
          </tr>
          <tr>
            <td data-i18n="teamTitle">Zusammenarbeit</td>
            <td data-i18n="teamDescription">
              Präsentieren, Aufgaben organisieren und gemeinsam
              an Projekten arbeiten.
            </td>
          </tr>
        </tbody>
      </table>
    </div>
  </section>

  <!-- 06 – KONTAKT UND STANDORT -->

  <section class="content-section contact-section reveal" id="kontakt">
    <div class="section-heading">
      <span class="section-number">06</span>
      <h2 data-i18n="contactTitle">Kontakt und Standort</h2>
    </div>

    <div class="contact-grid">

      <div class="contact-info">
        <h3 data-i18n="contactQuestion">Fragen zum Praktikum?</h3>

        <div class="contact-item">
          <strong data-i18n="contactPersonLabel">ANSPRECHPARTNERIN</strong>
          <p>Meike Molnar</p>
        </div>

        <div class="contact-item">
          <strong data-i18n="emailLabel">E-MAIL</strong>
          <a href="mailto:meike.molnar@accenture.com">meike.molnar@accenture.com</a>
        </div>

        <div class="contact-item">
          <strong data-i18n="phoneLabel">TELEFON – ACCENTURE CAMPUS KRONBERG</strong>
          <a href="tel:+4961739499">+49 6173 9499</a>
        </div>

        <div class="contact-item">
          <strong data-i18n="locationLabel">UNTERNEHMENSSTANDORT</strong>
          <p>
            Accenture – Campus Kronberg<br>
            Campus Kronberg 1<br>
            61476 Kronberg im Taunus
          </p>
        </div>

        <p class="contact-note" data-i18n="virtualNote">
          Hinweis: Das Schülerpraktikum findet ausschließlich virtuell
          statt. Die Adresse bezeichnet den Unternehmensstandort,
          nicht einen Praktikumsort vor Ort.
        </p>
      </div>

      <div class="map-container">
        <iframe
          src="https://maps.google.com/maps?q=Campus%20Kronberg%201%2C%2061476%20Kronberg%20im%20Taunus&t=&z=14&ie=UTF8&iwloc=&output=embed"
          title="Karte: Accenture Campus Kronberg"
          data-i18n-title="mapTitle"
          loading="lazy"
          referrerpolicy="no-referrer-when-downgrade"
          allowfullscreen>
        </iframe>

        <div class="map-caption">
          <strong data-i18n="mapCaptionTitle">Accenture Campus Kronberg</strong><br>
          <span data-i18n="mapAddress">Campus Kronberg 1, 61476 Kronberg im Taunus</span>
          <br>
          <span data-i18n="mapVirtual">Das Praktikum selbst findet virtuell statt.</span>
        </div>
      </div>

    </div>
  </section>

  <!-- FUSSZEILE -->

  <footer>
    <span data-i18n="footerText">Informationen für Eltern · Accenture</span>
    <a
      href="https://www.accenture.com/de-de"
      target="_blank"
      rel="noopener noreferrer"
      data-i18n="footerLink">
      Zur offiziellen Accenture-Website →
    </a>
  </footer>

  <!-- SPRACHUMSCHALTUNG -->

  <script>
    const translations = {
      de: {
        navHome: "Startseite",
        heroInfo: "INFORMATIONEN",
        heroFor: "FÜR",
        heroParents: "ELTERN",
        sloganFirst: "Entdecke deine",
        sloganPossibilities: "Möglichkeiten.",
        sloganSecond: "Gestalte deine",
        sloganFuture: "Zukunft.",

        aboutTitle: "Über uns",
        aboutStart: "Wir bei Accenture sind eine",
        aboutConsulting: "weltweit tätige Unternehmensberatung",
        aboutSupport: "die Unternehmen in den Bereichen",
        aboutFields: "Strategie, Technologie, Digitalisierung und Innovation",
        aboutSupportEnd: "unterstützt. Mit rund",
        aboutEmployees: "780.000 Mitarbeitenden in über 120 Ländern",
        aboutConnect: "verbinden wir Fachwissen mit modernster Technologie, um",
        aboutSustainable: "nachhaltige Lösungen",
        aboutFuture: "zu entwickeln und die Zukunft aktiv mitzugestalten.",

        participationTitle: "Ein Praktikum zum Mitmachen",
        participationIntro: "Das Praktikum verbindet neue Einblicke mit praktischer Erfahrung. Die Teilnehmenden arbeiten mit unterschiedlichen Betreuer:innen, bearbeiten Aufgaben allein und im Team und setzen ihre Ideen in eigenen Projekten um.",

        hoursTitle: "Praktikumszeiten",
        hoursTileDescription: "Zeiten und Pausen im Überblick.",
        digitalTileTitle: "Digitale Fähigkeiten",
        digitalTileDescription: "Einblicke in Coding und Webanwendungen.",
        collaborationTitle: "Zusammenarbeit",
        collaborationDescription: "Einzelaufgaben und Teamprojekte.",

        hoursIntro: "Die geplanten täglichen Zeiten im Überblick:",
        mondayThursday: "Montag bis Donnerstag",
        friday: "Freitag",
        lunch: "Mittagspause",
        breaks: "Zusätzliche Pausen",
        breaksDescription: "Kurze Pausen während des Tages",

        workflowTitle: "So wird das Praktikum gestaltet",
        workflowIntro: "Je nach Thema begleiten unterschiedliche Betreuer:innen die Teilnehmenden. Neben Workshops gibt es praktische Aufgaben, Fallstudien und gemeinsame Projektarbeit.",
        workshopsTitle: "Workshops",
        workshopsDescription: "Neue Themen kennenlernen und gemeinsam Lösungen erarbeiten.",
        casesTitle: "Case Studies",
        casesDescription: "Praxisnahe Fragestellungen analysieren und Lösungsansätze entwickeln.",
        projectsTitle: "Eigene Projekte",
        projectsDescription: "Ideen allein oder im Team in ein konkretes Ergebnis umsetzen.",

        skillsTitle: "Was wird vermittelt?",
        skillsIntro: "Das Praktikum vermittelt grundlegende Kompetenzen für digitale Projekte – von der Zusammenarbeit bis zur Entwicklung einfacher Webanwendungen.",
        skillsTableTopic: "Bereich",
        skillsTableContent: "Was wird vermittelt?",
        webTitle: "Webanwendungen",
        webDescription: "Grundlagen von HTML, CSS und JavaScript kennenlernen und für eigene digitale Anwendungen einsetzen.",
        digitalTitle: "Digitale Lösungen",
        digitalDescription: "Ideen entwickeln, Probleme analysieren und einfache technische Lösungen praktisch umsetzen.",
        teamTitle: "Zusammenarbeit",
        teamDescription: "Präsentieren, Aufgaben organisieren und gemeinsam an Projekten arbeiten.",

        contactTitle: "Kontakt und Standort",
        contactQuestion: "Fragen zum Praktikum?",
        contactPersonLabel: "ANSPRECHPARTNERIN",
        emailLabel: "E-MAIL",
        phoneLabel: "TELEFON – ACCENTURE CAMPUS KRONBERG",
        locationLabel: "UNTERNEHMENSSTANDORT",
        virtualNote: "Hinweis: Das Schülerpraktikum findet ausschließlich virtuell statt. Die Adresse bezeichnet den Unternehmensstandort, nicht einen Praktikumsort vor Ort.",
        mapTitle: "Karte: Accenture Campus Kronberg",
        mapCaptionTitle: "Accenture Campus Kronberg",
        mapAddress: "Campus Kronberg 1, 61476 Kronberg im Taunus",
        mapVirtual: "Das Praktikum selbst findet virtuell statt.",

        footerText: "Informationen für Eltern · Accenture",
        footerLink: "Zur offiziellen Accenture-Website →"
      },

      en: {
        navHome: "Home",
        heroInfo: "INFORMATION",
        heroFor: "FOR",
        heroParents: "PARENTS",
        sloganFirst: "Discover your",
        sloganPossibilities: "possibilities.",
        sloganSecond: "Shape your",
        sloganFuture: "future.",

        aboutTitle: "About us",
        aboutStart: "At Accenture, we are a",
        aboutConsulting: "global management consulting company",
        aboutSupport: "that supports businesses in",
        aboutFields: "strategy, technology, digital transformation and innovation",
        aboutSupportEnd: "With around",
        aboutEmployees: "780,000 employees in more than 120 countries",
        aboutConnect: "we combine expertise with advanced technology to develop",
        aboutSustainable: "sustainable solutions",
        aboutFuture: "and actively help shape the future.",

        participationTitle: "A Hands-on Internship",
        participationIntro: "The internship combines new insights with practical experience. Participants work with different mentors, complete tasks individually and in teams, and turn their ideas into projects.",

        hoursTitle: "Internship Hours",
        hoursTileDescription: "Overview of hours and breaks.",
        digitalTileTitle: "Digital Skills",
        digitalTileDescription: "An introduction to coding and web applications.",
        collaborationTitle: "Collaboration",
        collaborationDescription: "Individual tasks and team projects.",

        hoursIntro: "An overview of the planned daily schedule:",
        mondayThursday: "Monday to Thursday",
        friday: "Friday",
        lunch: "Lunch break",
        breaks: "Additional breaks",
        breaksDescription: "Short breaks throughout the day",

        workflowTitle: "How the Internship Works",
        workflowIntro: "Different mentors support participants depending on the topic. The programme includes workshops, practical tasks, case studies and team projects.",
        workshopsTitle: "Workshops",
        workshopsDescription: "Explore new topics and work together on solutions.",
        casesTitle: "Case Studies",
        casesDescription: "Analyse practical questions and develop possible solutions.",
        projectsTitle: "Your Own Projects",
        projectsDescription: "Turn ideas into tangible results individually or as a team.",

        skillsTitle: "What Will You Learn?",
        skillsIntro: "The internship introduces key skills for digital projects, from collaboration to developing simple web applications.",
        skillsTableTopic: "Area",
        skillsTableContent: "What will you learn?",
        webTitle: "Web Applications",
        webDescription: "Learn the basics of HTML, CSS and JavaScript and use them in your own digital applications.",
        digitalTitle: "Digital Solutions",
        digitalDescription: "Develop ideas, analyse problems and put simple technical solutions into practice.",
        teamTitle: "Collaboration",
        teamDescription: "Practise presenting, organising tasks and working together on projects.",

        contactTitle: "Contact and Location",
        contactQuestion: "Questions about the internship?",
        contactPersonLabel: "CONTACT PERSON",
        emailLabel: "EMAIL",
        phoneLabel: "PHONE – ACCENTURE CAMPUS KRONBERG",
        locationLabel: "COMPANY LOCATION",
        virtualNote: "Please note: The student internship takes place entirely online. The address is the company location, not an in-person internship venue.",
        mapTitle: "Map: Accenture Campus Kronberg",
        mapCaptionTitle: "Accenture Campus Kronberg",
        mapAddress: "Campus Kronberg 1, 61476 Kronberg im Taunus, Germany",
        mapVirtual: "The internship itself takes place online.",

        footerText: "Information for Parents · Accenture",
        footerLink: "Visit the official Accenture website →"
      },

      fr: {
        navHome: "Accueil",
        heroInfo: "INFORMATIONS",
        heroFor: "POUR",
        heroParents: "LES PARENTS",
        sloganFirst: "Découvre tes",
        sloganPossibilities: "possibilités.",
        sloganSecond: "Construis ton",
        sloganFuture: "avenir.",

        aboutTitle: "À propos de nous",
        aboutStart: "Chez Accenture, nous sommes un cabinet de conseil",
        aboutConsulting: "présent dans le monde entier",
        aboutSupport: "qui accompagne les entreprises dans les domaines de la",
        aboutFields: "stratégie, de la technologie, du numérique et de l’innovation",
        aboutSupportEnd: "Avec environ",
        aboutEmployees: "780 000 collaborateurs dans plus de 120 pays",
        aboutConnect: "nous associons expertise et technologies de pointe pour développer des",
        aboutSustainable: "solutions durables",
        aboutFuture: "et contribuer activement à façonner l’avenir.",

        participationTitle: "Un stage pratique et participatif",
        participationIntro: "Le stage associe découverte et expérience pratique. Les participants travaillent avec différents mentors, réalisent des tâches individuellement ou en équipe et concrétisent leurs idées dans des projets.",

        hoursTitle: "Horaires du stage",
        hoursTileDescription: "Aperçu des horaires et des pauses.",
        digitalTileTitle: "Compétences numériques",
        digitalTileDescription: "Découverte du codage et des applications web.",
        collaborationTitle: "Collaboration",
        collaborationDescription: "Tâches individuelles et projets en équipe.",

        hoursIntro: "Voici les horaires journaliers prévus :",
        mondayThursday: "Du lundi au jeudi",
        friday: "Vendredi",
        lunch: "Pause déjeuner",
        breaks: "Pauses supplémentaires",
        breaksDescription: "Courtes pauses au cours de la journée",

        workflowTitle: "Déroulement du stage",
        workflowIntro: "Selon le sujet, différents mentors accompagnent les participants. Le programme comprend des ateliers, des exercices pratiques, des études de cas et des projets en équipe.",
        workshopsTitle: "Ateliers",
        workshopsDescription: "Découvrir de nouveaux sujets et élaborer des solutions ensemble.",
        casesTitle: "Études de cas",
        casesDescription: "Analyser des situations concrètes et proposer des solutions.",
        projectsTitle: "Projets personnels",
        projectsDescription: "Concrétiser des idées seul ou en équipe.",

        skillsTitle: "Quelles compétences sont abordées ?",
        skillsIntro: "Le stage permet d’acquérir des compétences de base pour les projets numériques, de la collaboration au développement d’applications web simples.",
        skillsTableTopic: "Domaine",
        skillsTableContent: "Qu’apprend-on ?",
        webTitle: "Applications web",
        webDescription: "Découvrir les bases de HTML, CSS et JavaScript et les utiliser dans ses propres applications numériques.",
        digitalTitle: "Solutions numériques",
        digitalDescription: "Développer des idées, analyser des problèmes et mettre en pratique des solutions techniques simples.",
        teamTitle: "Collaboration",
        teamDescription: "Apprendre à présenter ses idées, organiser des tâches et travailler sur des projets en équipe.",

        contactTitle: "Contact et localisation",
        contactQuestion: "Des questions sur le stage ?",
        contactPersonLabel: "PERSONNE À CONTACTER",
        emailLabel: "E-MAIL",
        phoneLabel: "TÉLÉPHONE – CAMPUS ACCENTURE KRONBERG",
        locationLabel: "SITE DE L’ENTREPRISE",
        virtualNote: "À noter : le stage pour élèves se déroule entièrement à distance. Cette adresse correspond au site de l’entreprise, et non à un lieu de stage en présentiel.",
        mapTitle: "Carte : campus Accenture de Kronberg",
        mapCaptionTitle: "Campus Accenture de Kronberg",
        mapAddress: "Campus Kronberg 1, 61476 Kronberg im Taunus, Allemagne",
        mapVirtual: "Le stage lui-même se déroule à distance.",

        footerText: "Informations pour les parents · Accenture",
        footerLink: "Site officiel d’Accenture →"
      },

      es: {
        navHome: "Inicio",
        heroInfo: "INFORMACIÓN",
        heroFor: "PARA",
        heroParents: "FAMILIAS",
        sloganFirst: "Descubre tus",
        sloganPossibilities: "posibilidades.",
        sloganSecond: "Diseña tu",
        sloganFuture: "futuro.",

        aboutTitle: "Sobre nosotros",
        aboutStart: "En Accenture somos una consultora",
        aboutConsulting: "con presencia en todo el mundo",
        aboutSupport: "que ayuda a las empresas en los ámbitos de",
        aboutFields: "estrategia, tecnología, transformación digital e innovación",
        aboutSupportEnd: "Con aproximadamente",
        aboutEmployees: "780.000 profesionales en más de 120 países",
        aboutConnect: "combinamos experiencia y tecnología avanzada para desarrollar",
        aboutSustainable: "soluciones sostenibles",
        aboutFuture: "y contribuir activamente a dar forma al futuro.",

        participationTitle: "Prácticas para participar activamente",
        participationIntro: "Las prácticas combinan nuevos conocimientos con experiencia práctica. Los participantes trabajan con distintos mentores, realizan tareas individuales y en equipo y convierten sus ideas en proyectos.",

        hoursTitle: "Horario de las prácticas",
        hoursTileDescription: "Resumen de horarios y pausas.",
        digitalTileTitle: "Competencias digitales",
        digitalTileDescription: "Introducción a la programación y las aplicaciones web.",
        collaborationTitle: "Colaboración",
        collaborationDescription: "Tareas individuales y proyectos en equipo.",

        hoursIntro: "Este es el horario diario previsto:",
        mondayThursday: "De lunes a jueves",
        friday: "Viernes",
        lunch: "Pausa para comer",
        breaks: "Pausas adicionales",
        breaksDescription: "Pequeñas pausas durante el día",

        workflowTitle: "Cómo se desarrollan las prácticas",
        workflowIntro: "Según el tema, los participantes cuentan con distintos mentores. El programa incluye talleres, tareas prácticas, casos de estudio y proyectos en equipo.",
        workshopsTitle: "Talleres",
        workshopsDescription: "Conocer nuevos temas y desarrollar soluciones en equipo.",
        casesTitle: "Casos prácticos",
        casesDescription: "Analizar situaciones reales y proponer posibles soluciones.",
        projectsTitle: "Proyectos propios",
        projectsDescription: "Convertir ideas en resultados concretos individualmente o en equipo.",

        skillsTitle: "¿Qué se aprende?",
        skillsIntro: "Las prácticas permiten adquirir competencias básicas para proyectos digitales, desde la colaboración hasta el desarrollo de aplicaciones web sencillas.",
        skillsTableTopic: "Área",
        skillsTableContent: "¿Qué se aprende?",
        webTitle: "Aplicaciones web",
        webDescription: "Aprender los fundamentos de HTML, CSS y JavaScript y utilizarlos en aplicaciones digitales propias.",
        digitalTitle: "Soluciones digitales",
        digitalDescription: "Desarrollar ideas, analizar problemas y poner en práctica soluciones técnicas sencillas.",
        teamTitle: "Colaboración",
        teamDescription: "Practicar presentaciones, organizar tareas y trabajar en proyectos en equipo.",

        contactTitle: "Contacto y ubicación",
        contactQuestion: "¿Tienes preguntas sobre las prácticas?",
        contactPersonLabel: "PERSONA DE CONTACTO",
        emailLabel: "CORREO ELECTRÓNICO",
        phoneLabel: "TELÉFONO – CAMPUS DE ACCENTURE EN KRONBERG",
        locationLabel: "UBICACIÓN DE LA EMPRESA",
        virtualNote: "Importante: las prácticas para estudiantes se realizan íntegramente en línea. La dirección corresponde a la sede de la empresa, no a un lugar de prácticas presencial.",
        mapTitle: "Mapa: campus de Accenture en Kronberg",
        mapCaptionTitle: "Campus de Accenture en Kronberg",
        mapAddress: "Campus Kronberg 1, 61476 Kronberg im Taunus, Alemania",
        mapVirtual: "Las prácticas se realizan en línea.",

        footerText: "Información para familias · Accenture",
        footerLink: "Sitio web oficial de Accenture →"
      }
    };

    const languageSelect = document.getElementById("languageSelect");

    function setLanguage(language) {
      const dictionary = translations[language] || translations.de;

      document.documentElement.lang = language;

      const pageTitles = {
        de: "Informationen für Eltern | Accenture",
        en: "Information for Parents | Accenture",
        fr: "Informations pour les parents | Accenture",
        es: "Información para familias | Accenture"
      };

      document.title = pageTitles[language] || pageTitles.de;

      document.querySelectorAll("[data-i18n]").forEach(element => {
        const key = element.dataset.i18n;

        if (dictionary[key] !== undefined) {
          element.textContent = dictionary[key];
        }
      });

      document.querySelectorAll("[data-i18n-title]").forEach(element => {
        const key = element.dataset.i18nTitle;

        if (dictionary[key] !== undefined) {
          element.title = dictionary[key];
          element.setAttribute("title", dictionary[key]);
        }
      });
    }

    languageSelect.addEventListener("change", event => {
      setLanguage(event.target.value);
    });

    /* SANFTE SCROLL-ANIMATIONEN */

    const revealElements = document.querySelectorAll(".reveal");

    if ("IntersectionObserver" in window) {
      const observer = new IntersectionObserver(
        (entries, observerInstance) => {
          entries.forEach(entry => {
            if (entry.isIntersecting) {
              entry.target.classList.add("visible");
              observerInstance.unobserve(entry.target);
            }
          });
        },
        { threshold: 0.12 }
      );

      revealElements.forEach(element => observer.observe(element));
    } else {
      revealElements.forEach(element => element.classList.add("visible"));
    }
  </script>

</body>
</html>
