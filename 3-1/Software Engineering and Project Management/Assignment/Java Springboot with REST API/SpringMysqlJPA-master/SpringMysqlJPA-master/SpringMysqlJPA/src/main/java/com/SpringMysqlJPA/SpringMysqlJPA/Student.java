package com.SpringMysqlJPA.SpringMysqlJPA;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.Table;
import lombok.Data;

@Entity
@Data
@Table(name= "Student")
public class Student {

    @Id
    @Column(name="ID")
    private int id;

    @Column(name="Mark")
    private int mark;

    @Column(name="Name")
    private String name;
}
