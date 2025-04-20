import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.io.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

class Book implements Serializable {
  int id;
  String title;
  String author;
  String status;
  LocalDate dateAdded;
  LocalDate dueDate;

  Book(int id, String title, String author, LocalDate dateAdded) {
    this.id = id;
    this.title = title;
    this.author = author;
    this.status = "Available";
    this.dateAdded = dateAdded;
    this.dueDate = null;
  }
}

public class LibraryManagementSystemAdvanced extends JFrame {
  private final ArrayList<Book> books = new ArrayList<>();
  private int nextId = 1;
  private final DefaultTableModel tableModel;
  private final JTable table;
  private final JTextField searchField;
  private final String storageFile = "library_data.ser";

  public LibraryManagementSystemAdvanced() {
    setTitle("📚 Advanced Library Management System");
    setSize(1000, 600);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
    setLocationRelativeTo(null);
    setLayout(new BorderLayout(10, 10));
    getContentPane().setBackground(new Color(245, 245, 255));

    JLabel heading = new JLabel("💘 Advanced Library Management System", JLabel.CENTER);
    heading.setFont(new Font("Segoe UI", Font.BOLD, 26));
    heading.setBorder(new EmptyBorder(20, 10, 20, 10));
    heading.setForeground(new Color(60, 60, 120));
    add(heading, BorderLayout.NORTH);

    String[] columns = { "ID", "Title", "Author", "Date Added", "Status", "Due Date" };
    tableModel = new DefaultTableModel(columns, 0);
    table = new JTable(tableModel);
    table.setRowHeight(28);
    table.setFont(new Font("Segoe UI", Font.PLAIN, 14));
    table.getTableHeader().setFont(new Font("Segoe UI", Font.BOLD, 15));
    table.setBackground(new Color(255, 255, 255));
    table.setSelectionBackground(new Color(173, 216, 230));
    JScrollPane scrollPane = new JScrollPane(table);
    scrollPane.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
    add(scrollPane, BorderLayout.CENTER);

    JPanel bottomPanel = new JPanel(new GridLayout(2, 1));
    bottomPanel.setBackground(new Color(245, 245, 255));

    JPanel inputPanel = new JPanel(new FlowLayout());
    inputPanel.setBackground(new Color(245, 245, 255));

    JTextField titleField = new JTextField(12);
    JTextField authorField = new JTextField(12);
    JButton addButton = new JButton("➕ Add Book");
    JButton issueButton = new JButton("📤 Issue Book");
    JButton returnButton = new JButton("📥 Return Book");
    JButton removeButton = new JButton("❌ Remove Book");

    JButton[] buttons = { addButton, issueButton, returnButton, removeButton };
    for (JButton button : buttons) {
      button.setFocusPainted(false);
      button.setFont(new Font("Segoe UI", Font.BOLD, 14));
      button.setBackground(new Color(100, 149, 237));
      button.setForeground(Color.WHITE);
      button.setBorder(BorderFactory.createLineBorder(Color.DARK_GRAY, 1, true));
      button.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }

    titleField.setFont(new Font("Segoe UI", Font.PLAIN, 14));
    authorField.setFont(new Font("Segoe UI", Font.PLAIN, 14));

    inputPanel.add(new JLabel("Title:"));
    inputPanel.add(titleField);
    inputPanel.add(new JLabel("Author:"));
    inputPanel.add(authorField);
    inputPanel.add(addButton);
    inputPanel.add(issueButton);
    inputPanel.add(returnButton);
    inputPanel.add(removeButton);

    JPanel searchPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
    searchPanel.setBackground(new Color(245, 245, 255));
    searchPanel.add(new JLabel("🔍 Search:"));
    searchField = new JTextField(25);
    searchField.setFont(new Font("Segoe UI", Font.PLAIN, 14));
    searchPanel.add(searchField);

    bottomPanel.add(inputPanel);
    bottomPanel.add(searchPanel);
    add(bottomPanel, BorderLayout.SOUTH);

    loadBooks();
    updateTable();

    addButton.addActionListener(e -> {
      String title = titleField.getText().trim();
      String author = authorField.getText().trim();
      if (!title.isEmpty() && !author.isEmpty()) {
        Book book = new Book(nextId++, title, author, LocalDate.now());
        books.add(book);
        saveBooks();
        updateTable();
        titleField.setText("");
        authorField.setText("");
      } else {
        JOptionPane.showMessageDialog(this, "Enter title and author.", "Warning", JOptionPane.WARNING_MESSAGE);
      }
    });

    issueButton.addActionListener(e -> {
      int row = table.getSelectedRow();
      if (row >= 0) {
        int id = Integer.parseInt(table.getValueAt(row, 0).toString());
        for (Book book : books) {
          if (book.id == id && book.status.equals("Available")) {
            book.status = "Issued";
            book.dueDate = LocalDate.now().plusDays(7);
            break;
          }
        }
        saveBooks();
        updateTable();
      } else {
        JOptionPane.showMessageDialog(this, "Select a book to issue.", "Warning", JOptionPane.WARNING_MESSAGE);
      }
    });

    returnButton.addActionListener(e -> {
      int row = table.getSelectedRow();
      if (row >= 0) {
        int id = Integer.parseInt(table.getValueAt(row, 0).toString());
        for (Book book : books) {
          if (book.id == id && book.status.equals("Issued")) {
            book.status = "Available";
            book.dueDate = null;
            break;
          }
        }
        saveBooks();
        updateTable();
      } else {
        JOptionPane.showMessageDialog(this, "Select a book to return.", "Warning", JOptionPane.WARNING_MESSAGE);
      }
    });

    removeButton.addActionListener(e -> {
      int row = table.getSelectedRow();
      if (row >= 0) {
        int id = Integer.parseInt(table.getValueAt(row, 0).toString());
        books.removeIf(book -> book.id == id);
        saveBooks();
        updateTable();
      } else {
        JOptionPane.showMessageDialog(this, "Select a book to remove.", "Warning", JOptionPane.WARNING_MESSAGE);
      }
    });

    searchField.addKeyListener(new KeyAdapter() {
      public void keyReleased(KeyEvent e) {
        updateTable();
      }
    });
  }

  private void updateTable() {
    tableModel.setRowCount(0);
    String keyword = searchField.getText().toLowerCase();
    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
    for (Book book : books) {
      if (book.title.toLowerCase().contains(keyword) ||
          book.author.toLowerCase().contains(keyword) ||
          String.valueOf(book.id).contains(keyword)) {
        tableModel.addRow(new Object[] {
            book.id,
            book.title,
            book.author,
            book.dateAdded.format(formatter),
            book.status,
            book.dueDate != null ? book.dueDate.format(formatter) : "-"
        });
      }
    }
  }

  private void saveBooks() {
    try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(storageFile))) {
      oos.writeObject(books);
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  private void loadBooks() {
    File file = new File(storageFile);
    if (file.exists()) {
      try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(storageFile))) {
        ArrayList<Book> loaded = (ArrayList<Book>) ois.readObject();
        books.addAll(loaded);
        nextId = books.stream().mapToInt(b -> b.id).max().orElse(0) + 1;
      } catch (IOException | ClassNotFoundException e) {
        e.printStackTrace();
      }
    }
  }

  public static void main(String[] args) {
    SwingUtilities.invokeLater(() -> {
      LibraryManagementSystemAdvanced app = new LibraryManagementSystemAdvanced();
      app.setVisible(true);
    });
  }
}
