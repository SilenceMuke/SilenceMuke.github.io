#include <iostream>
#include <fstream>
#include <regex>

std::string replaceSecondOccurrence(const std::string& input, const std::regex& pattern, const std::string& replacement) {
    std::string result = input;
    auto begin = std::sregex_iterator(input.begin(), input.end(), pattern);
    auto end = std::sregex_iterator();
    int count = 0;
    std::smatch match;
    for (auto i = begin; i != end; ++i) {
        match = *i;
        count++;
        if (count == 2) {
            result.replace(match.position(), match.length(), replacement);
            break;
        }
    }
    return result;
}

int main() {
    std::ifstream inputFile("../site/index.html");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }
    std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    std::regex pattern1(R"(<div class="md-sidebar md-sidebar--secondary")");
    std::string replacement1 = R"($& id="index-toc")";
    std::string replacedContent = std::regex_replace(content, pattern1, replacement1);
    std::regex pattern2(R"(<div class=md-sidebar__scrollwrap>)");
    std::string replacement2 = R"(<div itemscope="" itemtype="http://schema.org/Person" class="profile_box" style="display:none;padding-left: 1rem;padding-right: 1.1rem;"><div class="author__avatar"><img src="/document/avatar.jpeg" class="author__avatar"></div>
  <div class="author__content">
    <hr><h3 class="author__name" style="font-size: .9rem !important;">Muke_慕可</h3>
    <p class="author__bio">Nankai University</p>
  </div>
  <div class="author__urls-wrapper">
    <!-- <button class="btn btn--inverse">More Info & Contact</button> -->
    <ul class="author__urls social-icons" style="">
        <li><div style="white-space: normal; margin-bottom: 1.3em;">「Eloim Essaim Eloim Essaim」
        </div></li>
    </ul>
    <div style="display: flex; gap: 19px;">
    <a href="https://github.com/SilenceMuke" title="github" class="social_icons" style="text-decoration: none; align-items: center;">
    <svg style="fill: var(--md-primary-bg-color); width:1.3em" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 496 512"><!--!Font Awesome Free 6.5.2 by @fontawesome - https://fontawesome.com License - https://fontawesome.com/license/free Copyright 2024 Fonticons, Inc.--><path d="M165.9 397.4c0 2-2.3 3.6-5.2 3.6-3.3 .3-5.6-1.3-5.6-3.6 0-2 2.3-3.6 5.2-3.6 3-.3 5.6 1.3 5.6 3.6zm-31.1-4.5c-.7 2 1.3 4.3 4.3 4.9 2.6 1 5.6 0 6.2-2s-1.3-4.3-4.3-5.2c-2.6-.7-5.5 .3-6.2 2.3zm44.2-1.7c-2.9 .7-4.9 2.6-4.6 4.9 .3 2 2.9 3.3 5.9 2.6 2.9-.7 4.9-2.6 4.6-4.6-.3-1.9-3-3.2-5.9-2.9zM244.8 8C106.1 8 0 113.3 0 252c0 110.9 69.8 205.8 169.5 239.2 12.8 2.3 17.3-5.6 17.3-12.1 0-6.2-.3-40.4-.3-61.4 0 0-70 15-84.7-29.8 0 0-11.4-29.1-27.8-36.6 0 0-22.9-15.7 1.6-15.4 0 0 24.9 2 38.6 25.8 21.9 38.6 58.6 27.5 72.9 20.9 2.3-16 8.8-27.1 16-33.7-55.9-6.2-112.3-14.3-112.3-110.5 0-27.5 7.6-41.3 23.6-58.9-2.6-6.5-11.1-33.3 2.6-67.9 20.9-6.5 69 27 69 27 20-5.6 41.5-8.5 62.8-8.5s42.8 2.9 62.8 8.5c0 0 48.1-33.6 69-27 13.7 34.7 5.2 61.4 2.6 67.9 16 17.7 25.8 31.5 25.8 58.9 0 96.5-58.9 104.2-114.8 110.5 9.2 7.9 17 22.9 17 46.4 0 33.7-.3 75.4-.3 83.6 0 6.5 4.6 14.4 17.3 12.1C428.2 457.8 496 362.9 496 252 496 113.3 383.5 8 244.8 8zM97.2 352.9c-1.3 1-1 3.3 .7 5.2 1.6 1.6 3.9 2.3 5.2 1 1.3-1 1-3.3-.7-5.2-1.6-1.6-3.9-2.3-5.2-1zm-10.8-8.1c-.7 1.3 .3 2.9 2.3 3.9 1.6 1 3.6 .7 4.3-.7 .7-1.3-.3-2.9-2.3-3.9-2-.6-3.6-.3-4.3 .7zm32.4 35.6c-1.6 1.3-1 4.3 1.3 6.2 2.3 2.3 5.2 2.6 6.5 1 1.3-1.3 .7-4.3-1.3-6.2-2.2-2.3-5.2-2.6-6.5-1zm-11.4-14.7c-1.6 1-1.6 3.6 0 5.9 1.6 2.3 4.3 3.3 5.6 2.3 1.6-1.3 1.6-3.9 0-6.2-1.4-2.3-4-3.3-5.6-2z"></path></svg>
    </a>
    <a href="https://www.zhihu.com/people/yin-cang-73-69" title="zhihu" class="social_icons" style="text-decoration: none; align-items: center;">
    <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 306 512" style="fill: var(--md-primary-bg-color); width:1.3em"><!--!Font Awesome Free 6.6.0 by @fontawesome - https://fontawesome.com License - https://fontawesome.com/license/free Copyright 2024 Fonticons, Inc.--><path d="M170.5 148.1v217.5l23.4 0 7.7 26.4 42-26.4h49.5V148.1H170.5zm97.8 193.9h-27.9l-27.9 17.5-5.1-17.5-11.9 0V171.8h72.8v170.3zm-118.5-94.4H97.5c1.7-27.1 2.2-51.6 2.2-73.5h51.2s2-22.6-8.6-22.3h-88.5c3.5-13.1 7.9-26.7 13.1-40.7 0 0-24.1 0-32.3 21.6-3.4 8.9-13.2 43.1-30.7 78.1 5.9-.6 25.4-1.2 36.8-22.2 2.1-5.9 2.5-6.7 5.1-14.5h28.9c0 10.5-1.2 66.9-1.7 73.4H20.8c-11.7 0-15.6 23.6-15.6 23.6h65.6C66.5 321.1 42.8 363.1 0 396.3c20.5 5.9 40.9-.9 51-9.9 0 0 23-20.9 35.6-69.3l54 64.9s7.9-26.9-1.2-40c-7.6-8.9-28.1-33.1-36.8-41.8L87.9 312c4.4-14 7-27.6 7.9-40.7h61.7s-.1-23.6-7.6-23.6v0zm412-1.6c20.8-25.6 45-58.6 "></path></svg>
    </a>
    <a href="https://space.bilibili.com/323034867" title="bilibili" class="social_icons" style="text-decoration: none; align-items: center;">
    <svg style="fill: var(--md-primary-bg-color); width:1.3em" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512"><!--!Font Awesome Free 6.5.2 by @fontawesome - https://fontawesome.com License - https://fontawesome.com/license/free Copyright 2024 Fonticons, Inc.--><path d="M488.6 104.1C505.3 122.2 513 143.8 511.9 169.8V372.2C511.5 398.6 502.7 420.3 485.4 437.3C468.2 454.3 446.3 463.2 419.9 464H92C65.6 463.2 43.8 454.2 26.7 436.8C9.7 419.4 .8 396.5 0 368.2V169.8C.8 143.8 9.7 122.2 26.7 104.1C43.8 87.8 65.6 78.8 92 78H121.4L96.1 52.2C90.3 46.5 87.4 39.2 87.4 30.4C87.4 21.6 90.3 14.3 96.1 8.6C101.8 2.9 109.1 0 117.9 0C126.7 0 134 2.9 139.8 8.6L213.1 78H301.1L375.6 8.6C381.7 2.9 389.2 0 398 0C406.8 0 414.1 2.9 419.9 8.6C425.6 14.3 428.5 21.6 428.5 30.4C428.5 39.2 425.6 46.5 419.9 52.2L394.6 78L423.9 78C450.3 78.8 471.9 87.8 488.6 104.1H488.6zM449.8 173.8C449.4 164.2 446.1 156.4 439.1 150.3C433.9 144.2 425.1 140.9 416.4 140.5H96.1C86.5 140.9 78.6 144.2 72.5 150.3C66.3 156.4 63.1 164.2 62.7 173.8V368.2C62.7 377.4 66 385.2 72.5 391.7C79 398.2 86.9 401.5 96.1 401.5H416.4C425.6 401.5 433.4 398.2 439.7 391.7C446 385.2 449.4 377.4 449.8 368.2L449.8 173.8zM185.5 216.5C191.8 222.8 195.2 230.6 195.6 239.7V273C195.2 282.2 191.9 289.9 185.8 296.2C179.6 302.5 171.8 305.7 162.2 305.7C152.6 305.7 144.7 302.5 138.6 296.2C132.5 289.9 129.2 282.2 128.8 273V239.7C129.2 230.6 132.6 222.8 138.9 216.5C145.2 210.2 152.1 206.9 162.2 206.5C171.4 206.9 179.2 210.2 185.5 216.5H185.5zM377 216.5C383.3 222.8 386.7 230.6 387.1 239.7V273C386.7 282.2 383.4 289.9 377.3 296.2C371.2 302.5 363.3 305.7 353.7 305.7C344.1 305.7 336.3 302.5 330.1 296.2C323.1 289.9 320.7 282.2 320.4 273V239.7C320.7 230.6 324.1 222.8 330.4 216.5C336.7 210.2 344.5 206.9 353.7 206.5C362.9 206.9 370.7 210.2 377 216.5H377z"/></svg>
    </a>
    <a href="mailto:matyyh@163.com" title="email" class="social_icons" style="text-decoration: none; align-items: center;">
    <svg style="fill: var(--md-primary-bg-color); width:1.3em" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512"><!--!Font Awesome Free 6.5.2 by @fontawesome - https://fontawesome.com License - https://fontawesome.com/license/free Copyright 2024 Fonticons, Inc.--><path d="M48 64C21.5 64 0 85.5 0 112c0 15.1 7.1 29.3 19.2 38.4L236.8 313.6c11.4 8.5 27 8.5 38.4 0L492.8 150.4c12.1-9.1 19.2-23.3 19.2-38.4c0-26.5-21.5-48-48-48H48zM0 176V384c0 35.3 28.7 64 64 64H448c35.3 0 64-28.7 64-64V176L294.4 339.2c-22.8 17.1-54 17.1-76.8 0L0 176z"></path></svg>
    </a>
</div>
  </div>
</div>
    <div class=md-sidebar__scrollwrap id="_main_sidebar">)";
    std::string replacedContent2 = replaceSecondOccurrence(replacedContent, pattern2, replacement2);
    std::regex pattern3(R"(<h1>Home</h1>)");
    std::string replacement3 = R"()";
    std::string replacedContent3 = std::regex_replace(replacedContent2, pattern3, replacement3);
    inputFile.close();
    std::ofstream outputFile("../site/index.html");
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }
    outputFile << replacedContent3;
    outputFile.close();
    std::cout << "Replacement completed successfully." << std::endl;
    return 0;
}
