#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Web {
    int idx;
    string url;
    int basic_score = 0;
    double link_score = 0;
    double total_score = 0;
    vector<string> ahref;
};


bool cmp(Web& a, Web& b) {
    if (a.total_score == b.total_score) return a.idx < b.idx;
    return a.total_score > b.total_score;
}

Web splitInfo(string word, string page) {
    Web site;
    // 본인 url
    int idx = page.find("<meta property");
    string tmp = "";
    for (int i = idx + 33; i < page.size(); i++) {
        if (page[i] == '"') break;
        tmp += page[i];
    }
    site.url = tmp;

    // word 갯수
    int front = page.find("<body>");
    int rear = page.find("</body>");
    tmp = "";
    for (int i = front + 7; i < rear - 1; i++) {
        if (page[i] >= 'A' && page[i] <= 'Z') {
            tmp += page[i] - 'A' + 'a';
        }
        else if (page[i] >= 'a' && page[i] <= 'z') {
            tmp += page[i];
        }
        else {
            if (tmp != "") {
                if (tmp == word) site.basic_score++;
                tmp = "";
            }
        }
    }

    // 외부링크
    idx = 0;
    while (true) {
        idx = page.find("<a href=", idx);
        if (idx == -1) break;
        tmp = "";
        for (int i = idx + 9; i < page.size(); i++) {
            if (page[i] == '"') break;
            tmp += page[i];
        }
        site.ahref.push_back(tmp);
        idx += tmp.size();
    }

    // 링크점수
    site.link_score = (double)site.basic_score / site.ahref.size();

    return site;
}


int solution(string word, vector<string> pages) {
    int answer = 0;

    for (int i = 0; i < word.size(); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') word[i] -= 'A' - 'a';
    }

    vector<Web> sites;
    for (string page : pages) {
        sites.push_back(splitInfo(word, page));
    }

    for (int i = 0; i < sites.size(); i++) {
        sites[i].idx = i;
        sites[i].total_score += sites[i].basic_score;
        for (string s : sites[i].ahref) {
            for (int j = 0; j < sites.size(); j++) {
                if (sites[j].url == s) {
                    sites[j].total_score += sites[i].link_score;
                    break;
                }
            }
        }
    }

    sort(sites.begin(), sites.end(), cmp);

    return sites[0].idx;
}

int main() {
    string word = "Blind";
    vector<string> pages = { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>" };
    cout << solution(word, pages);
    return 0;
}
