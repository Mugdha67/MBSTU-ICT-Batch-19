package com.example.quizgame.repository;

import com.example.quizgame.model.User;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

@Repository
public class QuizRepository {

    private final JdbcTemplate jdbcTemplate;

    public QuizRepository(JdbcTemplate jdbcTemplate) {
        this.jdbcTemplate = jdbcTemplate;
    }

    public User findUserById(String studentId) {
        try {
            return jdbcTemplate.query(
                    "SELECT * FROM users WHERE student_id = ?",
                    new Object[]{studentId},
                    rs -> rs.next() ? new User(studentId, rs.getString("name")) : null
            );
        } catch (Exception e) {
            System.err.println("Error finding user: " + e.getMessage());
            return null;
        }
    }

    public void saveScore(String studentId, int score) {
        try {
            jdbcTemplate.update("INSERT INTO scores (student_id, score) VALUES (?, ?)", studentId, score);
        } catch (Exception e) {
            System.err.println("Error saving score: " + e.getMessage());
        }
    }
}
