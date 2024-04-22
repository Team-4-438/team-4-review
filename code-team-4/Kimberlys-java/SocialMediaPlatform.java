import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
//------------------Users------------------
class User {
    String username;
    String displayName;
    String state;
    List<String> friends;
    
    //Constructor
    public User(String username, String displayName, String state, List<String> friends) {
        this.username = username;
        this.displayName = displayName;
        this.state = state;
        this.friends = friends;
    }
    
    //Accessors
    public String getUsername() {
        return username;
    }

    public String getDisplayName() {
        return displayName;
    }

    public String getState() {
        return state;
    }

    public List<String> getFriends() {
        return friends;
    }
}
//--------------------------Posts-----------------------
class Post {
    String postId;
    String userId;
    String visibility;

    //Constructor
    public Post(String postId, String userId, String visibility) {
        this.postId = postId;
        this.userId = userId;
        this.visibility = visibility;
    }

    //Accessors
    public String getPostId() {
        return postId;
    }

    public String getUserId() {
        return userId;
    }

    public String getVisibility() {
        return visibility;
    }
}
//---------------Social Media Platform---------------------
public class SocialMediaPlatform {
    private Map<String, User> users;
    private List<Post> posts;

    public SocialMediaPlatform() {
        this.users = new HashMap<>();
        this.posts = new ArrayList<>();
    }
//Loading information from User files
    public void loadUserData(String filePath) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(filePath));
        String line;
        while ((line = reader.readLine()) != null) {
            String[] parts = line.split(";");
            String username = parts[0];
            String displayName = parts[1];
            String state = parts[2];
            List<String> friends = parseFriendsList(parts[3]);
            users.put(username, new User(username, displayName, state, friends));
        }
        reader.close();
    }
//Reformating Friends List
    private List<String> parseFriendsList(String friendsListString) {
        List<String> friendsList = new ArrayList<>();
        if (!friendsListString.equals("[]")) {
            String[] friends = friendsListString.substring(1, friendsListString.length() - 1).split(",");
            for (String friend : friends) {
                friendsList.add(friend.trim());
            }
        }
        return friendsList;
    }
//Loading in information from Post files
    public void loadPostData(String filePath) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(filePath));
        String line;
        while ((line = reader.readLine()) != null) {
            String[] parts = line.split(";");
            String postId = parts[0];
            String userId = parts[1];
            String visibility = parts[2];
            posts.add(new Post(postId, userId, visibility));
        }
        reader.close();
    }
// Checking post for visibility status
    public void checkVisibility(String postId, String username) {
        for (Post post : posts) {
            if (post.getPostId().equals(postId)) {
                if (post.getVisibility().equals("public")) {
                    System.out.println("Access Permitted");
                    return;
                } else if (post.getVisibility().equals("friend")) {
                    User user = users.get(username);
                    if (user != null && user.getFriends().contains(post.getUserId())) {
                        System.out.println("Access Permitted");
                        return;
                    }
                }
            }
        }
        System.out.println("Access Denied");
    }
// Retrieving postID's based on username
    public void retrievePosts(String username) {
        for (Post post : posts) {
                if (post.getVisibility().equals("public")) {
                    System.out.println(post.getPostId());
                } else if (post.getVisibility().equals("friend")) {
                    User user = users.get(username);
                    if (user != null && user.getFriends().contains(post.getUserId())) {
                        System.out.println(post.getPostId());
                    } 
                    if (user != null && user.getUsername().equals(post.getUserId())){
                        System.out.println(post.getPostId());
                    }
                }
        }
    }

    public void searchUsersByLocation(String state) {
        for (User user : users.values()) {
            if (user.getState().equals(state)) {
                System.out.println(user.getDisplayName());
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        SocialMediaPlatform platform = new SocialMediaPlatform();
        boolean loaded = false;

        while (true) {
            System.out.println("Select an option:");
            System.out.println("1. Load input data");
            System.out.println("2. Check visibility");
            System.out.println("3. Retrieve posts");
            System.out.println("4. Search users by location");
            System.out.println("5. Exit");
            int option = scanner.nextInt();
            scanner.nextLine();  // Consume newline

            switch (option) {
                case 1:
                    //Load in users
                    platform.loadUserData("user-info.txt");
                    //load in posts
                    platform.loadPostData("post-info.txt");

                    System.out.println("Data loaded successfully.");
                    loaded = true;
                    break;
                case 2:
                    if (!loaded) {
                        System.out.println("Data not loaded. Please load data first.");
                        break;
                    }
                    System.out.println("Enter post ID:");
                    String postId = scanner.nextLine();
                    System.out.println("Enter username:");
                    String username = scanner.nextLine();
                    platform.checkVisibility(postId, username);
                    break;
                case 3:
                    if (!loaded) {
                        System.out.println("Data not loaded. Please load data first.");
                        break;
                    }
                    System.out.println("Enter username:");
                    String user = scanner.nextLine();
                    platform.retrievePosts(user);
                    break;
                case 4:
                    if (!loaded) {
                        System.out.println("Data not loaded. Please load data first.");
                        break;
                    }
                    System.out.println("Enter state location:");
                    String state = scanner.nextLine();
                    platform.searchUsersByLocation(state);
                    break;
                case 5:
                    System.out.println("Exiting program.");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid option. Please select again.");
            }
        }
    }
}


        
    

    