<!DOCTYPE html>
<html>
<head>
    <title>PwmMusic</title>
    <script>
    var currentLanguage = 'english'; 

    function switchLanguage(lang) {
        currentLanguage = lang;
        updateContent();
    }

    function updateContent() {

        var titleText = currentLanguage === 'chinese' ? '使用PWM输出播放《东方红》' : 'Playing "The East is Red" with PWM Output';
        document.getElementById('title').innerText = titleText;


        var introText = currentLanguage === 'chinese' ? 
            '本文档描述了如何使用脉冲宽度调制（PWM）信号来驱动无源蜂鸣器播放《东方红》的旋律。' : 
            'This document describes how to use Pulse Width Modulation (PWM) signals to drive a passive buzzer to play the melody of "The East is Red."';
        document.getElementById('intro').innerText = introText;


        var introTitleText = currentLanguage === 'chinese' ? '简介' : 'Introduction';
        document.getElementById('introTitle').innerText = introTitleText;


    }

    window.onload = updateContent;
    </script>
</head>
<body>


<button onclick="switchLanguage('chinese')">中文</button>
<button onclick="switchLanguage('english')">English</button>


<div id="content">
    <h1 id="title"></h1>
    <h3 id="introTitle"></h3>
    <p id="intro"></p>

</div>

</body>
</html>