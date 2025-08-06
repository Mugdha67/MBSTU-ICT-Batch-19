package com.example.quizgame.controller;

import com.example.quizgame.model.User;
import com.example.quizgame.repository.QuizRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

@Controller
public class QuizController {

    @Autowired
    private QuizRepository quizRepository;

    private final String[] questions = {
            "বাংলার শেষ স্বাধীন নবাব কে ছিলেন?",
            "পলাশীর যুদ্ধ কত সালে হয়েছিল?"
    };

    private final String[] answers = {
            "সিরাজউদ্দৌলা",
            "১৭৫৭"
    };

    private final int POINTS_PER_QUESTION = 18;

    @GetMapping("/")
    public String home() {
        return "index";
    }

    @PostMapping("/start-quiz")
    public String startQuiz(@RequestParam String studentId, Model model) {
        User user = quizRepository.findUserById(studentId);
        if (user != null) {
            model.addAttribute("studentId", studentId);
            model.addAttribute("userName", user.getName());
            model.addAttribute("questions", questions);
            return "quiz";
        } else {
            model.addAttribute("error", "শিক্ষার্থী আইডি খুঁজে পাওয়া যায়নি!");
            return "index";
        }
    }

    @PostMapping("/submit-quiz")
    public String submitQuiz(@RequestParam String studentId,
                             @RequestParam String answer1,
                             @RequestParam String answer2,
                             Model model) {
        int score = 0;
        if (answer1.trim().equalsIgnoreCase(answers[0])) score += POINTS_PER_QUESTION;
        if (answer2.trim().equalsIgnoreCase(answers[1])) score += POINTS_PER_QUESTION;

        quizRepository.saveScore(studentId, score);
        model.addAttribute("score", score);
        return "result";
    }
}
