package com.example.quizgame.model;

public class Score {
    private String studentId;
    private int score;

    public Score(String studentId, int score) {
        this.studentId = studentId;
        this.score = score;
    }

    public String getStudentId() {
        return studentId;
    }

    public void setStudentId(String studentId) {
        this.studentId = studentId;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }
}
